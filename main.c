#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "order.h"
#include "queue.h"
#include "stack.h"
#include "circular.h"
#include "history.h"

// Access the head from order.c for recursion and searching
extern Order *head;

int main() {
    int choice;

    // Initialize all Data Structures
    initQueue();
    initStack();

    while (1) {
        printf("\n======= FOOD DELIVERY SYSTEM =======\n");
        printf("1.  Add Menu Item\n");
        printf("2.  Display Menu\n");
        printf("3.  Place Order\n");
        printf("4.  Display Active Orders\n");
        printf("5.  Search Order\n");
        printf("6.  Cancel Order\n");
        printf("7.  Send Order to Kitchen\n");
        printf("8.  Process/Cook Order\n");
        printf("9.  Undo Last Cancel (Restore Order)\n");
        printf("10. Add Delivery Rider\n");
        printf("11. Assign Next Rider\n");
        printf("12. View Completed History\n");
        printf("13. Exit\n");
        printf("Enter Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n'); // Clear buffer
            continue;
        }

        switch (choice) {
            case 1: 
                addMenuItem(); 
                break;
            case 2: 
                displayMenu(); 
                break;
            case 3: 
                placeOrder(); 
                break;
            case 4: 
                displayActiveOrders(); 
                break;
            case 5: {
                int sId;
                printf("Enter Order ID to search: ");
                scanf("%d", &sId);
                searchOrderRecursive(head, sId);
                break;
            }
            case 6: {
                int idToCancel;
                printf("Enter Order ID to cancel: ");
                scanf("%d", &idToCancel);
                
                // Check if order exists before attempting cancellation
                if (isOrderIdDuplicate(idToCancel)) {
                    cancelOrder(idToCancel); 
                } else {
                    printf("Error: Order #%d does not exist.\n", idToCancel);
                }
                break;
            }
            case 7: {
                int qId;
                printf("Enter Order ID to send to kitchen: ");
                scanf("%d", &qId);
                
                // BUG FIX: Verify the order exists in active list before queueing
                if (isOrderIdDuplicate(qId)) {
                    sendToKitchen(qId);
                } else {
                    printf("Error: Order #%d not found in active orders!\n", qId);
                }
                break;
            }
            case 8: {
                int cookedId = processNextOrder();
                if (cookedId != -1) {
                    printf("Order #%d is COOKED!\n", cookedId);
                    addToHistory(cookedId); 
                }
                break;
            }
            case 9: {
                // BUG FIX: Pop full data structure and re-insert into linked list
                UndoLog restoredData = popUndo();
                if (restoredData.orderId != -1) {
                    restoreOrder(restoredData.orderId, restoredData.customerName, restoredData.foodId);
                } 
                break;
            }
            case 10: {
                char rName[50];
                printf("Enter Rider Name: ");
                scanf("%s", rName);
                addRider(rName);
                break;
            }
            case 11: 
                assignNextRider(); 
                break;
            case 12: 
                displayHistoryForward(); 
                break;
            case 13: 
                printf("Exiting System...\n");
                exit(0);
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}