#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circular.h"

Rider* currentRider = NULL;

void addRider(char* name) {
    Rider* newRider = (Rider*)malloc(sizeof(Rider));
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
        printf("No riders available!\n");
        return;
    }
    currentRider = currentRider->next; // Moves to the next person in the circle
    printf("Order assigned to Rider: %s\n", currentRider->name);
}