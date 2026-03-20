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
void sortMenuByPrice();
void searchMenuRecursive(int index, int targetId);
void displayMenu();
int isFoodIdValid(int targetId); // Validation helper

#endif