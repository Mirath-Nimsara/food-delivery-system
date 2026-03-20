#include <stdio.h>
#include <string.h>
#include "menu.h"

MenuItem menuList[MAX_MENU]; 
int menuCount = 0; 

// Helper function to check if a Food ID exists
int isFoodIdValid(int targetId) {
    for (int i = 0; i < menuCount; i++) {
        if (menuList[i].id == targetId) {
            return 1; // ID found
        }
    }
    return 0; // ID not found
}

void addMenuItem() {
    if (menuCount >= MAX_MENU) {
        printf("Error: Menu is full!\n");
        return;
    }

    int tempId;
    printf("\n--- Add New Menu Item ---\n");
    printf("Enter Food ID: ");
    scanf("%d", &tempId);

    // BUG FIX: Prevent duplicate Menu IDs
    if (isFoodIdValid(tempId)) {
        printf("Error: Food ID %d already exists in the menu!\n", tempId);
        return;
    }

    menuList[menuCount].id = tempId;
    
    printf("Enter Food Name: ");
    getchar(); 
    fgets(menuList[menuCount].name, 50, stdin);
    menuList[menuCount].name[strcspn(menuList[menuCount].name, "\n")] = 0; 

    printf("Enter Price: ");
    scanf("%f", &menuList[menuCount].price);

    printf("Enter Popularity (1-10): ");
    scanf("%d", &menuList[menuCount].popularity);

    menuCount++;
    printf("Item added successfully!\n");
}

void sortMenuByPrice() {
    for (int i = 0; i < menuCount - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < menuCount; j++) {
            if (menuList[j].price < menuList[min_idx].price)
                min_idx = j;
        }
        MenuItem temp = menuList[min_idx];
        menuList[min_idx] = menuList[i];
        menuList[i] = temp;
    }
    printf("Menu sorted by price!\n");
}

void searchMenuRecursive(int index, int targetId) {
    if (index >= menuCount) {
        printf("Item with ID %d not found in menu.\n", targetId);
        return;
    }
    if (menuList[index].id == targetId) {
        printf("Found: %s - Price: %.2f\n", menuList[index].name, menuList[index].price);
        return;
    }
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