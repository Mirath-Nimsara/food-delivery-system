#ifndef STACK_H
#define STACK_H

#define MAX_STACK 100

// Structure to hold all details of a cancelled order
typedef struct {
    int orderId;
    char customerName[50];
    int foodId;
} UndoLog;

typedef struct {
    UndoLog logs[MAX_STACK]; // Array of structs
    int top;
} UndoStack;

void initStack();
void pushUndo(int id, char* name, int fId);
UndoLog popUndo();

#endif