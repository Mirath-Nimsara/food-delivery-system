#ifndef MENU_H
#define MENU_H

#define MAX_MENU 50

typedef struct {
    int id;
    char name[50];
    float price;
    int popularity;
} MenuItem;

// Function Prototypes
void addMenuItem();
void displayMenuById();         // Bubble Sort
void displayMenuByPrice();      // Selection Sort
void displayMenuByPopularity(); // Insertion Sort
void printMenuArray(MenuItem arr[], int count);
int isFoodIdValid(int targetId);

#endif