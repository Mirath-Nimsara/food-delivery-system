#include <stdio.h>
#include "queue.h"

KitchenQueue kitchen;
int orderReadyForPickup = -1;

// BUG FIX: Ready Queue to store multiple cooked orders for riders
int readyQueue[MAX_QUEUE];
int rFront = 0, rRear = -1;

void initQueue() {
    kitchen.front = -1;
    kitchen.rear = -1;
    orderReadyForPickup = -1;
    rFront = 0;
    rRear = -1;
}

int isOrderInQueue(int orderId) {
    if (kitchen.front == -1) return 0;
    for (int i = kitchen.front; i <= kitchen.rear; i++) {
        if (kitchen.items[i] == orderId) {
            return 1;
        }
    }
    return 0;
}

void sendToKitchen(int orderId) {
    if (kitchen.rear == MAX_QUEUE - 1) {
        printf("Error: Kitchen queue is full!\n");
        return;
    }
    
    if (isOrderInQueue(orderId)) {
        printf("Error: Order #%d is already in the kitchen queue.\n", orderId);
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
    
  
    readyQueue[++rRear] = orderId;
    orderReadyForPickup = orderId; 
    
    printf("Kitchen has finished cooking Order #%d.\n", orderId);
    return orderId;
}

void displayKitchenQueue() {
    if (kitchen.front == -1) {
        printf("Kitchen queue is empty.\n");
        return;
    }
    printf("\n--- KITCHEN QUEUE ---\n");
    for (int i = kitchen.front; i <= kitchen.rear; i++) {
        printf("[%d] ", kitchen.items[i]);
    }
    printf("\n");
}