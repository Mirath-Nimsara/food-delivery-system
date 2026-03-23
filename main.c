#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "order.h"
#include "queue.h"
#include "stack.h"
#include "circular.h"
#include "history.h"

extern Order *head;

int main() {
    int choice;
    initQueue();
    initStack();

    while (1) {
        printf("\n======= FOOD DELIVERY SYSTEM =======\n");
        printf("1. Add Menu | 2. Display Menu | 3. Place Order  | 4. View Orders\n");
        printf("5. Search   | 6. Cancel       | 7. To Kitchen   | 8. Cook Order\n");
        printf("9. UNDO     | 10. Add Rider   | 11. Assign Rider| 12. History         | 13. Exit\n");
        printf("Enter Choice: ");
        
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1: addMenuItem(); break;
            case 2: {
                int sub;
                printf("\n1. By ID | 2. By Price | 3. By Popularity\nChoice: ");
                scanf("%d", &sub);
                if(sub==1) displayMenuById();
                else if(sub==2) displayMenuByPrice();
                else if(sub==3) displayMenuByPopularity();
                break;
            }
            case 3: placeOrder(); break;
            case 4: displayActiveOrders(); break;
            case 5: {
                int sId; printf("Search Order ID: "); scanf("%d", &sId);
                searchOrderRecursive(head, sId);
                break;
            }
            case 6: {
                int cId; printf("ID to cancel: "); scanf("%d", &cId);
                cancelOrder(cId); break;
            }
            case 7: {
                int qId;
                printf("Enter Order ID to send to kitchen: ");
                scanf("%d", &qId);
                
                // First check: Does the order even exist?
                if (isOrderIdDuplicate(qId)) {
                    // Second check happens inside this function now:
                    sendToKitchen(qId);
                } else {
                    printf("Error: Order #%d not found in active orders!\n", qId);
                }
                break;
            }
            case 8: {
                int cooked = processNextOrder();
                if(cooked != -1) addToHistory(cooked);
                break;
            }
            case 9: {
                UndoLog log = popUndo();
                if(log.orderId != -1) restoreOrder(log.orderId, log.customerName, log.foodId);
                break;
            }
            case 10: {
                char name[50]; printf("Rider Name: "); scanf("%s", name);
                addRider(name); break;
            }
            case 11: assignNextRider(); break;
            case 12: displayHistoryForward(); break;
            case 13: exit(0);
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}