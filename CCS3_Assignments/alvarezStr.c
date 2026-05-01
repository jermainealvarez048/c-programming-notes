/* 
Name: Jermaine Jalen Dikembe R. Alvarez

Topic: Structures, Array of Structures

Problem:
- Write a program that stimulates a simple inventory system.

Description:
- This program simulates a simple inventory system for ALVAREZ Enterprise.
- This system allows the user to add new items, edit item information, process 
  sales, receive goods, and display all stored items.

-Date-
Started: 01.20.2026
Ended: 01.23.2026
*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define ITEM_NAME_LEN 30
#define ITEM_NUM 100
#define FLUSH while (getchar() != '\n')

typedef struct {
	int number;
	char name[ITEM_NAME_LEN];
	short quantity;
	float price;
} ITEM_INVENTORY;

int add_new_item(ITEM_INVENTORY menu[], int i);
int find_item(ITEM_INVENTORY menu[], int i, int num);
void edit_item(ITEM_INVENTORY menu[], int i);
void item_sales(ITEM_INVENTORY menu[], int i);
void item_good_receipt(ITEM_INVENTORY menu[], int i);
void display_items(ITEM_INVENTORY menu[], int i);

int main(void) {
	ITEM_INVENTORY menu[ITEM_NUM];
	int total_items = 0;
	int choice;
	
	do {
		system("cls");
		printf("ALVAREZ Enterprise\n");
		printf("1] Add New Item\n");
		printf("2] Edit Item Information\n");
		printf("3] Sales\n");
		printf("4] Good Receipt\n");
		printf("5] Display All Items\n");
		printf("6] Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);
		
		int check;
		switch (choice) {
			case 1: check = add_new_item(menu, total_items);
				if (check)
					total_items++; 
				break;
			case 2: edit_item(menu, total_items);
				break;
			case 3: item_sales(menu, total_items);
				break;
			case 4: item_good_receipt(menu, total_items);
				break;
			case 5:	display_items(menu, total_items);
				break;
			case 6: 
				printf("\nThank You\n");
				break;
			default: printf("\nInvalid Choice!\n");
				printf("\nPress ENTER to continue...");
				getch();
		}	
	} while (choice != 6);
	
	return 0;
}

int add_new_item(ITEM_INVENTORY menu[], int i) {
	printf("\nItem Number: ");
	scanf("%d", &menu[i].number);
	for (int j = 0; j < i; j++) {
		if (menu[j].number == menu[i].number) {
			printf("Invalid! Item Duplicate.\n");
			printf("\nPress ENTER to continue...");
			getch();
			return 0;
		}
	}
	
	FLUSH;
	printf("Item Name: ");
	gets(menu[i].name);
	printf("Quantity: ");
	scanf("%d", &menu[i].quantity);
	printf("Selling Price: ");
	scanf("%f", &menu[i].price);
	
	return 1;
}

int find_item(ITEM_INVENTORY menu[], int i, int num) {
	int j;
	for (j = 0; j < i; j++) 
		if (menu[j].number == num) 
			return j;
	return -1;
}

void edit_item(ITEM_INVENTORY menu[], int i) {
	int num;
	printf("\nItem Number: ");
	scanf("%d", &num);
	
	int j = find_item(menu, i, num);
	if (j == -1) {
		printf("Invalid! Item does not exists.\n");
		printf("\nPress ENTER to continue...");
		getch();
		return;
	}
	
	FLUSH;
	printf("New Item Name: ");
	gets(menu[j].name);
	printf("New Selling Price: ");
	scanf("%f", &menu[j].price);
}

void item_sales(ITEM_INVENTORY menu[], int i) {
	int num;
	printf("\nItem Number: ");
	scanf("%d", &num);
	
	int j = find_item(menu, i, num);
	if (j == -1) {
		printf("Invalid! Item does not exists.\n");
		printf("\nPress ENTER to continue...");
		getch();
		return;
	}
	
	int bought_items;
	printf("Number of %s bought: ", menu[j].name);
	scanf("%d", &bought_items);
	
	if (bought_items < 0) {
		printf("Invalid! Negative Input.\n");
		printf("\nPlease ENTER to continue...");
		getch();
		return;
	}
	else if (menu[j].quantity == 0 || bought_items > menu[j].quantity) {
		printf("Item out of stock or Item is insufficient.\n");
		printf("\nPlease ENTER to continue...");
		getch();
		return;
	}
	
	menu[j].quantity -= bought_items;
}

void item_good_receipt(ITEM_INVENTORY menu[], int i) {
	int num;
	printf("\nItem Number: ");
	scanf("%d", &num);
	
	int j = find_item(menu, i, num);
	if (j == -1) {
		printf("Invalid! Item does not exists.\n");
		printf("\nPress ENTER to continue...");
		getch();
		return;
	}  
	
	int received_items;
	printf("%s Quantity Received: ", menu[j].name);
	scanf("%d", &received_items);
	
	if (received_items < 0) {
		printf("Invalid! Negative Input.\n");
		printf("\nPress ENTER to continue...");
		getch();
		return;
	}
	
	menu[j].quantity += received_items;
}

void display_items(ITEM_INVENTORY menu[], int i) {
	for (int j = 0; j < i; j++) {
		printf("\nItem Number: %d\n", menu[j].number);
		printf("Item Name: %s\n", menu[j].name);
		printf("Quantity: %d\n", menu[j].quantity);
		printf("Selling Price: %.2f\n", menu[j].price);
	}
	getch();
}