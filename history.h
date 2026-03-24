#ifndef HISTORY_H
#define HISTORY_H

typedef struct HistoryNode {
    int orderId;
    struct HistoryNode* next;
    struct HistoryNode* prev;
} HistoryNode;

void addToHistory(int id);
void displayHistoryForward();

#endif