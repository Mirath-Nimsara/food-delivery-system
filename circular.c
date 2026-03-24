#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"
#include "queue.h"

// Pulling multiple cooked orders from queue.c
extern int readyQueue[];
extern int rFront, rRear;

Rider* currentRider = NULL;

void addRider(char* name) {
    Rider* newRider = (Rider*)malloc(sizeof(Rider));
    if (newRider == NULL) return;
    
    strcpy(newRider->name, name);

    if (currentRider == NULL) {
        currentRider = newRider;
        newRider->next = currentRider; 
    } else {
        newRider->next = currentRider->next;
        currentRider->next = newRider;
    }
    printf("Rider %s added to the rotation.\n", name);
}

void assignNextRider() {
    if (currentRider == NULL) {
        printf("Error: No riders available!\n");
        return;
    }

    if (rFront > rRear) {
        printf("Error: No cooked orders ready for pickup!\n");
        return;
    }

    int currentOrder = readyQueue[rFront++]; 
    currentRider = currentRider->next; 
    printf("SUCCESS: Order #%d assigned to Rider: %s\n", currentOrder, currentRider->name);
    
  
    if (rFront > rRear) orderReadyForPickup = -1;
}