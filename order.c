#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "order.h"
#include "menu.h"
#include "stack.h"

Order* head = NULL; 

// Helper: Check if ID exists in list
int isOrderIdDuplicate(int id) {
    Order* temp = head;
    while (temp != NULL) {
        if (temp->orderId == id) return 1;
        temp = temp->next;
    }
    return 0;
}

// RESTORE Function for Undo
void restoreOrder(int id, char* name, int fId) {
    Order* newNode = (Order*)malloc(sizeof(Order));
    if (newNode == NULL) return;
    newNode->orderId = id;
    newNode->foodId = fId;
    strcpy(newNode->customerName, name);
    newNode->next = head;
    head = newNode;
    printf("Order #%d restored successfully!\n", id);
}

// SEARCH Function (This is what you are missing!)
void searchOrderRecursive(Order* current, int targetId) {
    if (current == NULL) {
        printf("Order ID %d not found in active orders.\n", targetId);
        return;
    }
    if (current->orderId == targetId) {
        printf("Found! Customer: %s, Food ID: %d\n", current->customerName, current->foodId);
        return;
    }
    searchOrderRecursive(current->next, targetId);
}

void placeOrder() {
    int oId, fId;
    printf("\nEnter Order ID: ");
    scanf("%d", &oId);
    if (isOrderIdDuplicate(oId)) { printf("ID exists!\n"); return; }
    
    printf("Enter Food ID: ");
    scanf("%d", &fId);
    if (!isFoodIdValid(fId)) { printf("Not in menu!\n"); return; }

    Order* n = (Order*)malloc(sizeof(Order));
    n->orderId = oId;
    n->foodId = fId;
    printf("Customer Name: ");
    getchar();
    fgets(n->customerName, 50, stdin);
    n->customerName[strcspn(n->customerName, "\n")] = 0;
    
    n->next = head;
    head = n;
    printf("Order placed!\n");
}

void cancelOrder(int id) {
    if (!head) return;
    Order *temp = head, *prev = NULL;
    while (temp && temp->orderId != id) {
        prev = temp; 
        temp = temp->next;
    }
    if (!temp) { printf("Not found!\n"); return; }

    pushUndo(temp->orderId, temp->customerName, temp->foodId);

    if (!prev) head = temp->next;
    else prev->next = temp->next;
    free(temp);
    printf("Order #%d cancelled.\n", id);
}

void displayActiveOrders() {
    Order* t = head;
    if(!t) {
        printf("No active orders.\n");
        return;
    }
    while(t) {
        printf("ID: %d | Customer: %s | Food: %d\n", t->orderId, t->customerName, t->foodId);
        t = t->next;
    }
}