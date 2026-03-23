#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"
#include "queue.h" // Needed for orderReadyForPickup

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

    // Check if an order was actually cooked in queue.c
    if (orderReadyForPickup == -1) {
        printf("Error: No cooked orders ready for pickup! Process an order first.\n");
        return;
    }

    currentRider = currentRider->next; 
    printf("SUCCESS: Order #%d assigned to Rider: %s\n", orderReadyForPickup, currentRider->name);
    
    // Clear the ready status so the same order isn't assigned twice
    orderReadyForPickup = -1; 
}