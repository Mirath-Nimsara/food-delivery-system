#ifndef ORDER_H
#define ORDER_H

typedef struct Order {
    int orderId;
    char customerName[50];
    int foodId;
    struct Order* next;
} Order;

void placeOrder();
void displayActiveOrders();
void cancelOrder(int id);
void searchOrderRecursive(Order* current, int targetId);
int isOrderIdDuplicate(int id);
void restoreOrder(int id, char* name, int fId);
void removeFromListInternal(int id); 

#endif