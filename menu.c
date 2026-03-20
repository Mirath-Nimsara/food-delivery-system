#include <stdio.h>
#include <string.h>
#include "menu.h"

// Global Variables for the Menu
MenuItem menuList[MAX_MENU]; 
int menuCount = 0; 

// 1. Function using Array
void addMenuItem() {
    if (menuCount >= MAX_MENU) {
        printf("Error: Menu is full!\n");
        return;
    }

    printf("\n--- Add New Menu Item ---\n");
    printf("Enter Food ID: ");
    scanf("%d", &menuList[menuCount].id);
    
    printf("Enter Food Name: ");
    getchar(); // Clear buffer
    fgets(menuList[menuCount].name, 50, stdin);
    menuList[menuCount].name[strcspn(menuList[menuCount].name, "\n")] = 0; // Remove newline

    printf("Enter Price: ");
    scanf("%f", &menuList[menuCount].price);

    printf("Enter Popularity (1-10): ");
    scanf("%d", &menuList[menuCount].popularity);

    menuCount++;
    printf("Item added successfully!\n");
}

// 2. Function using Selection Sort (Algorithm Requirement)
void sortMenuByPrice() {
    for (int i = 0; i < menuCount - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < menuCount; j++) {
            if (menuList[j].price < menuList[min_idx].price)
                min_idx = j;
        }
        // Swap the elements
        MenuItem temp = menuList[min_idx];
        menuList[min_idx] = menuList[i];
        menuList[i] = temp;
    }
    printf("Menu sorted by price (Cheapest first)!\n");
}

// 3. Function using Recursion (Algorithm Requirement)
void searchMenuRecursive(int index, int targetId) {
    // Base Case: Not found
    if (index >= menuCount) {
        printf("Item with ID %d not found in menu.\n", targetId);
        return;
    }
    // Base Case: Found
    if (menuList[index].id == targetId) {
        printf("Found: %s - Price: %.2f\n", menuList[index].name, menuList[index].price);
        return;
    }
    // Recursive Step
    searchMenuRecursive(index + 1, targetId);
}

void displayMenu() {
    printf("\n--- CURRENT MENU ---\n");
    printf("ID\tName\t\tPrice\tPopularity\n");
    for (int i = 0; i < menuCount; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", 
               menuList[i].id, menuList[i].name, menuList[i].price, menuList[i].popularity);
    }
}