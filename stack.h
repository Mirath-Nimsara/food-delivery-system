#ifndef STACK_H
#define STACK_H

#define MAX_STACK 100

typedef struct {
    int orderId;
    char customerName[50];
    int foodId;
} UndoLog;

typedef struct {
    UndoLog logs[MAX_STACK]; 
    int top;
} UndoStack;

void initStack();
void pushUndo(int id, char* name, int fId);
UndoLog popUndo();

#endif