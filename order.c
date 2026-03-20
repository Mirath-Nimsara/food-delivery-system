#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"

Order* head = NULL; // The start of our Linked List

// 1. Function using Linked List (Insertion)
void placeOrder() {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    if (newOrder == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("\n--- Place New Order ---\n");
    printf("Enter Order ID: ");
    scanf("%d", &newOrder->orderId);
    
    printf("Enter Customer Name: ");
    getchar(); // Clear buffer
    fgets(newOrder->customerName, 50, stdin);
    newOrder->customerName[strcspn(newOrder->customerName, "\n")] = 0;

    printf("Enter Food ID from Menu: ");
    scanf("%d", &newOrder->foodId);

    newOrder->next = NULL;

    // If list is empty, this becomes the head
    if (head == NULL) {
        head = newOrder;
    } else {
        // Otherwise, go to the end of the list and attach it
        Order* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newOrder;
    }
    printf("Order #%d placed successfully!\n", newOrder->orderId);
}

// 2. Function using Recursion on a Linked List
void searchOrderRecursive(Order* current, int targetId) {
    // Base Case 1: End of list reached
    if (current == NULL) {
        printf("Order ID %d not found in active orders.\n", targetId);
        return;
    }
    // Base Case 2: Found the ID
    if (current->orderId == targetId) {
        printf("Order Found! Customer: %s, Food ID: %d\n", 
               current->customerName, current->foodId);
        return;
    }
    // Recursive Step: Move to the next node
    searchOrderRecursive(current->next, targetId);
}

void displayActiveOrders() {
    if (head == NULL) {
        printf("\nNo active orders at the moment.\n");
        return;
    }
    Order* temp = head;
    printf("\n--- ACTIVE ORDERS ---\n");
    while (temp != NULL) {
        printf("Order ID: %d | Customer: %s | Food ID: %d\n", 
               temp->orderId, temp->customerName, temp->foodId);
        temp = temp->next;
    }
}




void cancelOrder() {
    int id;
    if (head == NULL) {
        printf("No active orders to cancel.\n");
        return;
    }

    printf("Enter Order ID to cancel: ");
    scanf("%d", &id);

    Order *temp = head, *prev = NULL;

    // Case 1: The order to be deleted is the HEAD (the first one)
    if (temp != NULL && temp->orderId == id) {
        head = temp->next; // Change head to the second node
        free(temp);        // Free the memory of the old head
        printf("Order #%d cancelled and removed.\n", id);
        return;
    }

    // Case 2: Search for the order to be deleted
    // Keep track of the previous node so we can "skip" the deleted one
    while (temp != NULL && temp->orderId != id) {
        prev = temp;
        temp = temp->next;
    }

    // If order was not found
    if (temp == NULL) {
        printf("Order ID %d not found.\n", id);
        return;
    }

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp); // Free memory
    printf("Order #%d cancelled and removed.\n", id);
}