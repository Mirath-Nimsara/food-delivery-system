#include <stdio.h>
#include "stack.h"

UndoStack undo;

void initStack() {
    undo.top = -1;
}

// 1. Push Operation (Save an ID for undoing)
void pushUndo(int orderId) {
    if (undo.top == MAX_STACK - 1) {
        return; // Stack full, silently ignore or handle error
    }
    undo.top++;
    undo.log[undo.top] = orderId;
}

// 2. Pop Operation (Retrieve last saved ID)
int popUndo() {
    if (undo.top == -1) {
        printf("Nothing to undo!\n");
        return -1;
    }
    int lastId = undo.log[undo.top];
    undo.top--;
    return lastId;
}

void displayUndoLog() {
    if (undo.top == -1) {
        printf("Undo log is empty.\n");
        return;
    }
    printf("\n--- RECENT ACTIONS (Stack) ---\n");
    for (int i = undo.top; i >= 0; i--) {
        printf("[Action for Order #%d] \n", undo.log[i]);
    }
}