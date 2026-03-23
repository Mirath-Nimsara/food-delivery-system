#include <stdio.h>
#include "queue.h"

KitchenQueue kitchen;
int orderReadyForPickup = -1;

void initQueue() {
    kitchen.front = -1;
    kitchen.rear = -1;
    orderReadyForPickup = -1;
}

// NEW: Helper function to check if order is already in the kitchen
int isOrderInQueue(int orderId) {
    if (kitchen.front == -1) return 0; // Queue is empty
    
    for (int i = kitchen.front; i <= kitchen.rear; i++) {
        if (kitchen.items[i] == orderId) {
            return 1; // Found it!
        }
    }
    return 0;
}

void sendToKitchen(int orderId) {
    // 1. Check if kitchen is full
    if (kitchen.rear == MAX_QUEUE - 1) {
        printf("Error: Kitchen queue is full!\n");
        return;
    }
    
    // 2. Check if order is ALREADY in the kitchen (The Fix)
    if (isOrderInQueue(orderId)) {
        printf("Error: Order #%d is already in the kitchen queue. Do not re-send!\n", orderId);
        return;
    }

    if (kitchen.front == -1) kitchen.front = 0;
    
    kitchen.rear++;
    kitchen.items[kitchen.rear] = orderId;
    printf("Order #%d successfully sent to kitchen queue.\n", orderId);
}

int processNextOrder() {
    if (kitchen.front == -1 || kitchen.front > kitchen.rear) {
        printf("No pending orders in the kitchen.\n");
        return -1;
    }

    int orderId = kitchen.items[kitchen.front];
    kitchen.front++;
    
    if (kitchen.front > kitchen.rear) {
        kitchen.front = kitchen.rear = -1;
    }
    
    orderReadyForPickup = orderId; 
    printf("Kitchen has finished cooking Order #%d.\n", orderId);
    return orderId;
}