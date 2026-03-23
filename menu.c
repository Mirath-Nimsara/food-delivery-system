#include <stdio.h>
#include <string.h>
#include "menu.h"

MenuItem menuList[MAX_MENU]; 
int menuCount = 0; 

int isFoodIdValid(int targetId) {
    for (int i = 0; i < menuCount; i++) {
        if (menuList[i].id == targetId) return 1;
    }
    return 0;
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

    if (isFoodIdValid(tempId)) {
        printf("Error: Food ID %d already exists!\n", tempId);
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

void printMenuArray(MenuItem arr[], int count) {
    if (count == 0) {
        printf("Menu is empty!\n");
        return;
    }
    printf("\nID\tName\t\tPrice\tPopularity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t%d\n", arr[i].id, arr[i].name, arr[i].price, arr[i].popularity);
    }
}

void displayMenuById() {
    MenuItem temp[MAX_MENU];
    memcpy(temp, menuList, sizeof(MenuItem) * menuCount);
    for (int i = 0; i < menuCount - 1; i++) {
        for (int j = 0; j < menuCount - i - 1; j++) {
            if (temp[j].id > temp[j + 1].id) {
                MenuItem t = temp[j]; temp[j] = temp[j+1]; temp[j+1] = t;
            }
        }
    }
    printf("\n--- Sorted by ID (Bubble) ---");
    printMenuArray(temp, menuCount);
}

void displayMenuByPrice() {
    MenuItem temp[MAX_MENU];
    memcpy(temp, menuList, sizeof(MenuItem) * menuCount);
    for (int i = 0; i < menuCount - 1; i++) {
        int min = i;
        for (int j = i + 1; j < menuCount; j++) {
            if (temp[j].price < temp[min].price) min = j;
        }
        MenuItem t = temp[min]; temp[min] = temp[i]; temp[i] = t;
    }
    printf("\n--- Sorted by Price (Selection) ---");
    printMenuArray(temp, menuCount);
}

void displayMenuByPopularity() {
    MenuItem temp[MAX_MENU];
    memcpy(temp, menuList, sizeof(MenuItem) * menuCount);
    for (int i = 1; i < menuCount; i++) {
        MenuItem key = temp[i];
        int j = i - 1;
        while (j >= 0 && temp[j].popularity < key.popularity) {
            temp[j + 1] = temp[j];
            j--;
        }
        temp[j + 1] = key;
    }
    printf("\n--- Sorted by Popularity (Insertion) ---");
    printMenuArray(temp, menuCount);
}