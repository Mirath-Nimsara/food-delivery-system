#ifndef MENU_H
#define MENU_H

#define MAX_MENU 100 // Maximum items the array can hold

// Data Structure: Array (Requirement 1)
typedef struct {
    int id;
    char name[50];
    float price;
    int popularity; // Used later for Bubble Sort
} MenuItem;

// Function Prototypes (Declarations)
void addMenuItem();
void displayMenu();
void sortMenuByPrice(); // For Selection Sort requirement
void searchMenuRecursive(int index, int targetId); // For Recursion requirement

#endif