#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 100

typedef struct {
    int items[MAX_QUEUE];
    int front;
    int rear;
} KitchenQueue;

void initQueue();
void sendToKitchen(int orderId);
int processNextOrder();
void displayKitchenQueue();
int isOrderInQueue(int orderId);

extern int orderReadyForPickup; 

extern int readyQueue[];
extern int rFront, rRear;

#endif