/*
Name: Jermaine Jalen Dikembe R. Alvarez

Description:
A program that simulates a simple inventory system using relative file organization
- 

-Date-
Started: 03.26.2026
Ended: 03.27.2026
*/

//#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FLUSH while (getchar() != '\n')
#define NAME_LEN 30
#define DATE_LEN 25
#define MAX_ITEMS 7
#define MAX_SALES 51

typedef struct {
    int number;
    char name[NAME_LEN+1];
    short quantity;
    float price;
} Items;

typedef struct {
    int sales_number;
    char date[DATE_LEN+1];
    short item_number;
    short quantity_bought;
    float line_amount;
} Sales;

int create_skeletal_file(void);
int hash_modulo(int n, int max);
Items search_item(int n);
Sales search_sales(int n);
void add_item(void);
void edit_item(void);
void delete_item(void);
void add_sales(void);
void display_item(void);
void display_all_items(void);
void display_all_sales(void);

int main(void) {
    int create_file = create_skeletal_file();

    if (create_file == 0) 
        return 1;

    int choice;

    do {
        system("cls");
        printf("ALVAREZ Enterprise\n");
        printf("1] Add New Item\n");
        printf("2] Edit an Item\n");
        printf("3] Delete an Item\n");
        printf("4] Sales\n");
        printf("5] Display Specific Item\n");
        printf("6] Display All Inventory Items\n");
        printf("7] Display All Sales\n");
        printf("8] Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_item();
                break;
            case 2: edit_item();
                break;
            case 3: delete_item();
                break;
            case 4: add_sales();
                break;
            case 5: display_item();
                break;
            case 6: display_all_items();
                break;
            case 7: display_all_sales();
                break;
            case 8: printf("Thank You\n");
                break;
            default:
        }
    } while (choice != 8);

    return 0;
}

int create_skeletal_file(void) {
    FILE *fp1 = fopen("inventory.dat", "wb");
    FILE *fp2 = fopen("sales.dat", "wb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error! Unable to create file.\n");
        return 0;
    }

    Items item;
    Sales sale;

    for (int i = 1; i <= MAX_ITEMS; i++) {
        item.number = 0;
        strcpy(item.name, "");
        item.quantity = 0;
        item.price = 0.0;

        fwrite(&item, sizeof(Items), 1, fp1);
    }

    for (int i = 1; i <= MAX_SALES; i++) {
        sale.sales_number = 0;
        strcpy(sale.date, "");
        sale.item_number = 0;
        sale.quantity_bought = 0;
        sale.line_amount = 0.0;

        fwrite(&sale, sizeof(Sales), 1, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    return 1;
}

int hash_modulo(int n, int max) {
    int offset = n % max;
    return offset;
}

Items search_item(int n) {
    Items check1 = {0}, check2;
    FILE *fp = fopen("inventory.dat", "rb");

    if (fp == NULL) 
        return check1;

    int offset = hash_modulo(n, MAX_ITEMS);

    fseek(fp, offset * sizeof(Items), SEEK_SET);
    fread(&check2, sizeof(Items), 1, fp);
    fclose(fp);

    return check2;
}

Sales search_sales(int n) {
    Sales check1 = {0}, check2;
    FILE *fp = fopen("sales.dat", "rb");

    if (fp == NULL)
        return check1;
        
    int offset = hash_modulo(n, MAX_SALES);

    fseek(fp, offset * sizeof(Sales), SEEK_SET);
    fread(&check2, sizeof(Sales), 1, fp);
    fclose(fp);

    return check2;
}

void add_item(void) {
    system("cls");
    printf("Adding New Item to Invetory\n");

    FILE *fp = fopen("inventory.dat", "r+b");

    if (fp == NULL) {
        printf("\nError! Unable to open file.\n");
        printf("Press ENTER to go back to menu...");
        getch();
        return;
    }

    int check_num;
    char ch;

    do {
        printf("\nItem Number: ");
        scanf("%d", &check_num);

        if (check_num <= 0)
            printf("\nError! Enter valid item number.\n");
    } while (check_num <= 0);


    Items item = search_item(check_num);
    if (item.number == check_num) {
        fclose(fp);
        printf("\nInvalid! Item Number already exists.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }
    item.number = check_num;
    
    FLUSH;
    printf("Item Name: ");
    gets(item.name);
    printf("Quantity: ");
    scanf("%hd", &item.quantity);
    printf("Selling Price: ");
    scanf("%f", &item.price);

    int offset = hash_modulo(item.number, MAX_ITEMS);

    fseek(fp, offset * sizeof(Items), SEEK_SET);
    fwrite(&item, sizeof(Items), 1, fp);
    fclose(fp);

    printf("\nItem successfully added to inventory.\n");

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void edit_item(void) {
    system("cls");
    printf("Editing Item on Inventory\n");

    FILE *fp = fopen("inventory.dat", "r+b");

    if (fp == NULL) {
        printf("\nError! Unable to open file.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    int check_num;
    printf("Item Number: ");
    scanf("%d", &check_num);

    Items item = search_item(check_num);
    if (item.number != check_num) {
        fclose(fp);
        printf("\nInvalid! Item number not found.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    printf("\nItem Name: %s\n", item.name);
    FLUSH;
    printf("New Name: ");
    gets(item.name);
    printf("\nSelling Price: %.2f\n", item.price);
    printf("New Selling Price: ");
    scanf("%f", &item.price);

    int offset = hash_modulo(item.number, MAX_ITEMS);
    
    fseek(fp, offset * sizeof(Items), SEEK_SET);
    fwrite(&item, sizeof(Items), 1, fp);
    
    printf("\nItem successfully edited.\n");
    fclose(fp);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void delete_item(void) {
    system("cls");
    printf("Deleting Item on Inventory\n");

    FILE *fp = fopen("inventory.dat", "r+b");

    if (fp == NULL) {
        printf("\nError! Unable to open file.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    int check_num;
    printf("Item Number: ");
    scanf("%d", &check_num);

    Items item = search_item(check_num);
    if (item.number != check_num) {
        fclose(fp);
        printf("\nInvalid! Item number not found.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    char ch;

    printf("\nItem Name: %s\n", item.name);
    printf("Quantity: %hd\n", item.quantity);
    printf("Selling Price: %.2f\n", item.price);

    printf("\nContinue to delete item on inventory (Y/n): ");
    scanf(" %c", &ch);

    if (toupper(ch) == 'Y') {
        int offset = hash_modulo(item.number, MAX_ITEMS);

        item.number = 0;
        strcpy(item.name, "");
        item.quantity = 0;
        item.price = 0.0;

        fseek(fp, offset * sizeof(Items), SEEK_SET);
        fwrite(&item, sizeof(Items), 1, fp);
        
        printf("\nItem successfully deleted from inventory.\n");
    }
    fclose(fp);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void add_sales(void) {
    system("cls");
    printf("Recording Sales to Inventory\n");

    FILE *fp1 = fopen("sales.dat", "r+b");

    if (fp1 == NULL) {
        printf("\nError! Unable to open file.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    int check_num;
    char ch;

    do {
        printf("\nSales Number: ");
        scanf("%d", &check_num);

        if (check_num <= 0)
            printf("\nError! Enter valid sales number.\n");
    } while (check_num <= 0);
    
    Sales sale = search_sales(check_num);
    if (sale.sales_number == check_num) {
        fclose(fp1);
        printf("\nInvalid! Sales number already exists.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }
    sale.sales_number = check_num;

    FLUSH;
    printf("Date: ");
    gets(sale.date);
    printf("Item Number: ");
    scanf("%hd", &sale.item_number);

    Items item = search_item(sale.item_number);
    if (item.number != sale.item_number) {
        fclose(fp1);
        printf("\nInvalid! Item number not found.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    printf("Quantity bought: ");
    scanf("%hd", &sale.quantity_bought);

    if (sale.quantity_bought < 0) {
        fclose(fp1);
        printf("\nError! Invalid Item Quantity.\n");
        printf("Press ENTER to go back to menu...");
        getch();
        return;
    }

    if (item.quantity <= 0) {
        fclose(fp1);
        printf("\nInvalid! Item out of stock.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }
    else if (item.quantity < sale.quantity_bought) {
        fclose(fp1);
        printf("\nInvalid! Insufficient stock.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }
    item.quantity -= sale.quantity_bought;
    sale.line_amount = sale.quantity_bought * item.price;

    FILE *fp2 = fopen("inventory.dat", "r+b");

    if (fp2 == NULL) {
        fclose(fp1);
        printf("\nError! Unable to open file.\n");
        printf("Press ENTER to go back to menu...");
        getch();
        return;
    }

    int sales_offset = hash_modulo(sale.sales_number, MAX_SALES);
    int item_offset = hash_modulo(item.number, MAX_ITEMS);

    fseek(fp1, sales_offset * sizeof(Sales), SEEK_SET);
    fwrite(&sale, sizeof(Sales), 1, fp1);

    fseek(fp2, item_offset * sizeof(Items), SEEK_SET);
    fwrite(&item, sizeof(Items), 1, fp2);

    fclose(fp1);
    fclose(fp2);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void display_item(void) {
    system("cls");
    printf("Displaying Specific Item\n");

    int check_num;
    printf("Item Number: ");
    scanf("%d", &check_num);

    Items item = search_item(check_num);
    if (item.number != check_num) {
        printf("\nInvalid! Item number not found.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    printf("\nItem Number: %d\n", item.number);
    printf("Item Name: %s\n", item.name);
    printf("Quantity: %hd\n", item.quantity);
    printf("Selling Price: %.2f\n", item.price);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void display_all_items(void) {
    system("cls");
    printf("Displaying All Items\n");

    FILE *fp = fopen("inventory.dat", "rb");

    if (fp == NULL) {
        printf("\nError! Unable to open file.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    Items item;
    int count = 1;

    while (fread(&item, sizeof(Items), 1, fp) == 1) {
        if (item.number != 0) {
            printf("[%d]\n", count++);
            printf("Item Number: %d\n", item.number);
            printf("Item Name: %s\n", item.name);
            printf("Quantity: %hd\n", item.quantity);
            printf("Selling Price: %.2f\n\n", item.price);
        }
    }
    fclose(fp);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void display_all_sales(void) {
    system("cls");
    printf("Displaying All Sales\n");

    FILE *fp = fopen("sales.dat", "rb");

    if (fp == NULL) {
        printf("\nError! Unable to open file.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    Sales sale;
    int count = 1;

    while (fread(&sale, sizeof(Sales), 1, fp) == 1) {
        if (sale.sales_number != 0) {
            printf("[%d]\n", count++); 
            printf("Sales Number: %d\n", sale.sales_number);
            printf("Date: %s\n", sale.date);
            printf("Item Number: %hd\n", sale.item_number);
            printf("Quantity Bought: %hd\n", sale.quantity_bought);
            printf("Line Amount: %.2f\n\n", sale.line_amount);
        }
    }
    fclose(fp);

    printf("\nPress ENTER to go back to menu...");
    getch();
}