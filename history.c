#include <stdio.h>
#include <stdlib.h>
#include "history.h"

HistoryNode* historyHead = NULL;

void addToHistory(int id) {
    HistoryNode* newNode = (HistoryNode*)malloc(sizeof(HistoryNode));
    newNode->orderId = id;
    newNode->next = historyHead;
    newNode->prev = NULL;

    if (historyHead != NULL) historyHead->prev = newNode;
    historyHead = newNode;
    printf("Order #%d moved to History.\n", id);
}

void displayHistoryForward() {
    HistoryNode* temp = historyHead;
    printf("\n--- COMPLETE ORDER HISTORY ---\n");
    while (temp != NULL) {
        printf("[Order #%d] <-> ", temp->orderId);
        temp = temp->next;
    }
    printf("END\n");
}