#ifndef CIRCULAR_H
#define CIRCULAR_H

typedef struct Rider {
    char name[50];
    struct Rider* next;
} Rider;

void addRider(char* name);
void assignNextRider();
void displayRiders();

#endif