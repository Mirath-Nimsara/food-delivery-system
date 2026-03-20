#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "menu.h"
#include "stack.h"

Order* head = NULL; 

// Helper to check if an Order ID exists
int isOrderIdDuplicate(int id) {
    Order* temp = head;
    while (temp != NULL) {
        if (temp->orderId == id) return 1;
        temp = temp->next;
    }
    return 0;
}

// Function to put a cancelled order back into the list
void restoreOrder(int id, char* name, int fId) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    if (newOrder == NULL) return;

    newOrder->orderId = id;
    newOrder->foodId = fId;
    strcpy(newOrder->customerName, name);
    
    // Add to the front of the list
    newOrder->next = head;
    head = newOrder;
    printf("SUCCESS: Order #%d restored to Active Orders!\n", id);
}

void placeOrder() {
    int tId, fId;
    printf("\n--- Place New Order ---\n");
    printf("Enter Order ID: ");
    scanf("%d", &tId);

    if (isOrderIdDuplicate(tId)) {
        printf("Error: Order ID %d already exists!\n", tId);
        return;
    }

    printf("Enter Food ID from Menu: ");
    scanf("%d", &fId);
    if (!isFoodIdValid(fId)) {
        printf("Error: Food ID %d not in menu!\n", fId);
        return;
    }

    Order* newOrder = (Order*)malloc(sizeof(Order));
    newOrder->orderId = tId;
    newOrder->foodId = fId;

    printf("Enter Customer Name: ");
    getchar(); // Clear buffer
    fgets(newOrder->customerName, 50, stdin);
    newOrder->customerName[strcspn(newOrder->customerName, "\n")] = 0;

    newOrder->next = head;
    head = newOrder;
    printf("Order #%d placed successfully!\n", tId);
}

void searchOrderRecursive(Order* current, int targetId) {
    if (current == NULL) {
        printf("Order ID %d not found.\n", targetId);
        return;
    }
    if (current->orderId == targetId) {
        printf("Found! Customer: %s, Food ID: %d\n", current->customerName, current->foodId);
        return;
    }
    searchOrderRecursive(current->next, targetId);
}

void cancelOrder(int id) {
    if (head == NULL) return;
    Order *temp = head, *prev = NULL;

    while (temp != NULL && temp->orderId != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Order #%d not found!\n", id);
        return;
    }

    // Save to stack for UNDO before deleting
    pushUndo(temp->orderId, temp->customerName, temp->foodId);

    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;

    free(temp);
    printf("Order #%d cancelled.\n", id);
}

void displayActiveOrders() {
    Order* temp = head;
    if (temp == NULL) {
        printf("\nNo active orders.\n");
        return;
    }
    printf("\n--- ACTIVE ORDERS ---\n");
    while (temp != NULL) {
        printf("ID: %d | Customer: %s | Food ID: %d\n", 
               temp->orderId, temp->customerName, temp->foodId);
        temp = temp->next;
    }
}