#ifndef ORDER_H
#define ORDER_H

// Data Structure: Linked List (Requirement 2)
typedef struct Order {
    int orderId;
    char customerName[50];
    int foodId;        // Links to the ID in the Menu Array
    struct Order* next; // Pointer to the next node
} Order;

// Function Prototypes
void placeOrder();
void displayActiveOrders();
void searchOrderRecursive(Order* current, int targetId); 
void cancelOrder();

#endif