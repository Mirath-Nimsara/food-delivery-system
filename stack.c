#include <stdio.h>
#include <string.h>
#include "stack.h"

UndoStack undo;

void initStack() {
    undo.top = -1;
}

void pushUndo(int id, char* name, int fId) {
    if (undo.top == MAX_STACK - 1) return;
    
    undo.top++;
    undo.logs[undo.top].orderId = id;
    undo.logs[undo.top].foodId = fId;
    strcpy(undo.logs[undo.top].customerName, name);
}

UndoLog popUndo() {
    if (undo.top == -1) {
        UndoLog empty = {-1, "", -1};
        return empty;
    }
    return undo.logs[undo.top--];
}