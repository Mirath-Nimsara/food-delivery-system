#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "order.h"
#include "queue.h"
#include "stack.h"
#include "circular.h"
#include "history.h"

// Access the head from order.c for recursion
extern Order *head;

int main() {
    int choice, searchId;

    // Initialize all Data Structures
    initQueue();
    initStack();
    // Note: circular and history use head pointers initialized in their .c files

    while (1) {
        printf("\n======= FOOD DELIVERY SYSTEM =======\n");
        printf("--- Menu & Orders ---\n");
        printf("1.  Add Menu Item (Array)\n");
        printf("2.  Display Menu\n");
        printf("3.  Place Order (Linked List)\n");
        printf("4.  Display Active Orders\n");
        printf("5.  Search Order (Recursion)\n");
        printf("6.  Cancel Order (Linked List Deletion)\n");
        
        printf("\n--- Kitchen & Undo ---\n");
        printf("7.  Send Order to Kitchen (Queue Enqueue)\n");
        printf("8.  Process/Cook Order (Queue Dequeue)\n");
        printf("9.  Undo Last Cancel (Stack Pop)\n");
        
        printf("\n--- Riders & History ---\n");
        printf("10. Add Delivery Rider (Circular List)\n");
        printf("11. Assign Next Rider (Circular Rotation)\n");
        printf("12. View Completed History (Doubly Linked List)\n");
        printf("13. Exit\n");
        
        printf("\nEnter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a number.\n");
            while (getchar() != '\n'); 
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
            case 5:
                printf("Enter Order ID to search: ");
                scanf("%d", &searchId);
                searchOrderRecursive(head, searchId);
                break;
            case 6: {
                int idToCancel;
                printf("Enter Order ID to cancel: ");
                scanf("%d", &idToCancel);
                pushUndo(idToCancel); // Save to stack before deleting
                cancelOrder(idToCancel); 
                break;
            }
            case 7: {
                int qId;
                printf("Enter Order ID to send to kitchen: ");
                scanf("%d", &qId);
                sendToKitchen(qId);
                break;
            }
            case 8: {
                int cookedId = processNextOrder();
                if (cookedId != -1) {
                    printf("Order #%d is COOKED!\n", cookedId);
                    addToHistory(cookedId); // Move to Doubly Linked List
                }
                break;
            }
            case 9: {
                int restoredId = popUndo();
                if (restoredId != -1) {
                    printf("UNDO: Last cancelled ID %d logged.\n", restoredId);
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