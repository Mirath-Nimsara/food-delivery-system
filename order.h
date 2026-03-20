#ifndef ORDER_H
#define ORDER_H

typedef struct Order {
    int orderId;
    char customerName[50];
    int foodId;
    struct Order* next;
} Order;

// Function Prototypes - MUST BE HERE
void placeOrder();
void displayActiveOrders();
void searchOrderRecursive(Order* current, int targetId);
void cancelOrder(int id);
int isOrderIdDuplicate(int id);
void restoreOrder(int id, char* name, int fId); // Added this

#endif