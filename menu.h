#ifndef MENU_H
#define MENU_H

#define MAX_MENU 50

typedef struct {
    int id;
    char name[50];
    float price;
    int popularity;
} MenuItem;

void addMenuItem();
void displayMenuById();        
void displayMenuByPrice();     
void displayMenuByPopularity(); 
void printMenuArray(MenuItem arr[], int count);
int isFoodIdValid(int targetId);

#endif