#include <stdio.h>
#include "queue.h"

KitchenQueue kitchen;

// Initialize the queue pointers
void initQueue() {
    kitchen.front = -1;
    kitchen.rear = -1;
}

// 1. Enqueue Operation (Add to kitchen)
void sendToKitchen(int orderId) {
    if (kitchen.rear == MAX_QUEUE - 1) {
        printf("Kitchen is overloaded! Cannot take more orders.\n");
        return;
    }
    if (kitchen.front == -1) kitchen.front = 0;
    
    kitchen.rear++;
    kitchen.items[kitchen.rear] = orderId;
    printf("Order #%d sent to kitchen queue.\n", orderId);
}

// 2. Dequeue Operation (Cook/Process)
int processNextOrder() {
    if (kitchen.front == -1 || kitchen.front > kitchen.rear) {
        printf("No orders in the kitchen to process.\n");
        return -1;
    }

    int orderId = kitchen.items[kitchen.front];
    kitchen.front++;
    
    // Reset queue if it becomes empty
    if (kitchen.front > kitchen.rear) {
        kitchen.front = kitchen.rear = -1;
    }
    
    return orderId;
}

void displayKitchenQueue() {
    if (kitchen.front == -1) {
        printf("Kitchen queue is empty.\n");
        return;
    }
    printf("\n--- KITCHEN PENDING QUEUE ---\n");
    for (int i = kitchen.front; i <= kitchen.rear; i++) {
        printf("[Order #%d] ", kitchen.items[i]);
    }
    printf("\n");
}