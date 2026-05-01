/*
Laboratory Exercise No 5: Sequential File Organization

Name: Jermaine Jalen Dikembe R. Alvarez

Exercise:
- Write a menu driven program that allows the user to do the following:
    1. Add New Record to the file
    2. Edit a Record in the file
    3. Search and display a record from the file
    4. Delete a record from a file
    5. Display all records from the file
    6. Terminate the program
*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 40
#define FLUSH while (getchar() != '\n');

typedef struct {
    int id;
    char name[NAME_LEN+1];
    float balance;
} Customer;

Customer search_id(int key_id);
void add_record(void);
void edit_record(void);
void display_record(void);
void delete_record(void);
void display_all_records(void);

int main(void) {
    int choice;

    do {
        system("cls");
        printf("Customer Record System\n");
        printf("1] Add a Record\n");
        printf("2] Edit a Record\n");
        printf("3] Search and Display a Record\n");
        printf("4] Delete a Record\n");
        printf("5] Display all Records\n");
        printf("6] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_record();
                break;
            case 2: edit_record();
                break;
            case 3: display_record();
                break;
            case 4: delete_record();
                break;
            case 5: display_all_records();
                break;
            case 6: printf("\nThank You\n");
                break;
            default: printf("Error! Enter Valid Choice\n");
        }
    } while (choice != 6);

    return 0;
}

Customer search_id(int key_id) {
    Customer check1 = {0}, check2;
    FILE *fp = fopen("record.dat", "rb");

    if (fp == NULL)
        return check1;

    while (fread(&check2, sizeof(Customer), 1, fp) == 1) {
        if (check2.id == key_id) {
            fclose(fp);
            return check2;
        }
    }
    fclose(fp);

    return check1;
}

void add_record(void) {
    system("cls");
    printf("Adding Customer Record\n\n");
    
    Customer customer;

    do {
        printf("Customer ID: ");
        scanf("%d", &customer.id);

        if (customer.id <= 0)
            printf("Error! Enter Proper ID\n");
    } while (customer.id <= 0);

    Customer check = search_id(customer.id);
    if (check.id != 0) {
        printf("Invalid! Customer ID already exists\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    FLUSH;
    printf("Customer Name: ");
    gets(customer.name);
    printf("Customer Balance: ");
    scanf("%f", &customer.balance);

    FILE *fp = fopen("record.dat", "ab");
    
    if (fp == NULL) {
        printf("Error! Unable to open file\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    fwrite(&customer, sizeof(Customer), 1, fp);
    fclose(fp);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void edit_record(void) {
    system("cls");
    printf("Editing Customer Record\n");
    
    int customer_id;
    printf("Enter Customer ID: ");
    scanf("%d", &customer_id);

    Customer check = search_id(customer_id);

    if (check.id == 0) {
        printf("Invalid! Customer ID not found\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    FILE *fp1, *fp2;
    fp1 = fopen("record.dat", "rb");
    fp2 = fopen("temp.dat", "wb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error! Unable to open file\n");
        if (fp1 != NULL)
            fclose(fp1);
        if (fp2 != NULL)
            fclose(fp2);
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    Customer customer;  
    while (fread(&customer, sizeof(Customer), 1, fp1) == 1) {
        if (customer.id == check.id) {
            printf("\nCustomer Name: %s\n", customer.name);
            FLUSH;
            printf("New Customer Name: ");
            gets(customer.name);
            printf("\nCustomer Balance: %.2f\n", customer.balance);
            printf("New Customer Balance: ");
            scanf("%f", &customer.balance);
            fwrite(&customer, sizeof(Customer), 1, fp2);
        } else {
            fwrite(&customer, sizeof(Customer), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);

    fp1 = fopen("record.dat", "wb");
    fp2 = fopen("temp.dat", "rb");

    while (fread(&customer, sizeof(Customer), 1, fp2) == 1) 
        fwrite(&customer, sizeof(Customer), 1, fp1);
    fclose(fp1);
    fclose(fp2);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void display_record(void) {
    system("cls");
    printf("Display Specific Customer Record\n");

    int customer_id;
    printf("Enter Customer ID: ");
    scanf("%d", &customer_id);

    Customer customer = search_id(customer_id);

    if (customer.id == 0) {
        printf("Invalid! Customer ID not found\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    printf("\nCustomer ID: %d\n", customer.id);
    printf("Customer Name: %s\n", customer.name);
    printf("Customer Balance: %.2f\n", customer.balance);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void delete_record(void) {
    system("cls");
    printf("Deleting Customer Record\n");

    int customer_id;
    printf("Enter Customer ID: ");
    scanf("%d", &customer_id);

    Customer check = search_id(customer_id);

    if (check.id == 0) {
        printf("Invalid! Customer ID not found\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    FILE *fp1, *fp2;
    fp1 = fopen("record.dat", "rb");
    fp2 = fopen("temp.dat", "wb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error! Unable to open file\n");
        if (fp1 != NULL)
            fclose(fp1);
        if (fp2 != NULL)
            fclose(fp2);
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    Customer customer;
    char ch;
    while (fread(&customer, sizeof(Customer), 1, fp1) == 1) {
        if (customer.id == check.id) {
            printf("\nCustomer ID: %d\n", customer.id);
            printf("Customer Name: %s\n", customer.name);
            printf("Customer Balance: %.2f\n", customer.balance);
            printf("Do you want to delete customer data (Y/n): ");
            scanf(" %c", &ch);
            if (ch != 'Y' && ch != 'y')
                fwrite(&customer, sizeof(Customer), 1, fp2);
            else 
                printf("Customer record successfully deleted\n");
        } else {
            fwrite(&customer, sizeof(Customer), 1, fp2);
        }
    }
    fclose(fp1);
    fclose(fp2);

    fp1 = fopen("record.dat", "wb");
    fp2 = fopen("temp.dat", "rb");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error! Unable to open file\n");
        if (fp1 != NULL)
            fclose(fp1);
        if (fp2 != NULL)
            fclose(fp2);
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    while (fread(&customer, sizeof(Customer), 1, fp2) == 1)
        fwrite(&customer, sizeof(Customer), 1, fp1);
    fclose(fp1);
    fclose(fp2);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void display_all_records(void) {
    system("cls");
    printf("Displaying All Customer Records\n");

    Customer customer;
    FILE *fp = fopen("record.dat", "rb");

    if (fp == NULL) {
        printf("Error! Unable to open file\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    int count = 1;
    while (fread(&customer, sizeof(Customer), 1, fp) == 1) {
        printf("\n[%d]\n", count++);
        printf("Customer ID: %d\n", customer.id);
        printf("Customer Name: %s\n", customer.name);
        printf("Customer Balance: %.2f\n", customer.balance);
    }
    fclose(fp);

    printf("\nPress ENTER to go back to menu...");
    getch();
}