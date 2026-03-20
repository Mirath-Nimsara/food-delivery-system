#ifndef STACK_H
#define STACK_H

#define MAX_STACK 50

// Data Structure: Stack (Requirement 7)
typedef struct {
    int log[MAX_STACK];
    int top;
} UndoStack;

// Function Prototypes
void initStack();
void pushUndo(int orderId); // Push
int popUndo();             // Pop
void displayUndoLog();

#endif