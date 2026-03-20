#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 50

// Data Structure: Queue (Requirement 6)
typedef struct {
    int items[MAX_QUEUE];
    int front;
    int rear;
} KitchenQueue;

// Function Prototypes
void initQueue();
void sendToKitchen(int orderId); // Enqueue
int processNextOrder();          // Dequeue
void displayKitchenQueue();

#endif