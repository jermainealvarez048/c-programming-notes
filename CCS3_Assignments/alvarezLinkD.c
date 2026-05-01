/*
Name: Jermaine Jalen Dikembe R. Alvarez

Topic: Linked-list Implicatoin

Problem: 
 - Write a program that simulates a simple inventory system using singly linked-list.

Description:
A program that simulates a simple system using singly linked-list:
- it adds new unique items to the inventory that is arranged sequentially
- it deletes a specific exisiting item from inventory
- records the sales and also updates the inventory 
- records the goods receipt and also updates the inventory
- displays a specific item from the inventory
- displays all exisiting items from inventory
- displays all sales records
- displays good receipt transactions

-Date-
Started: 03.13.2026
Ended:  03.14.2026
*/

// #include <conio.h>
#include <stdio.h>
#include <stdlib.h>

// Macro Definitions
#define ITEM_NAME_LEN 30
#define DATE_LEN 20
#define FLUSH while (getchar() != '\n')

// Linked-Lists Inventory
typedef struct item_node *Item_inventory;
typedef struct sales_node *Sales_record;
typedef struct receipt_node *Goods_receipt;
typedef struct {
    int number;
    char name[ITEM_NAME_LEN+1];
    short quantity;
    float selling_price;
} Items;
typedef struct {
    char date[DATE_LEN+1];
    short item_number;
    short quantity_bought;
    float line_amount;
} Sales;
typedef struct {
    char date[DATE_LEN+1];
    short item_number;
    short quantity_delivered;
} Receipt;

struct item_node {
    Items item;
    Item_inventory next;
} ITEM;
struct sales_node {
    Sales sales;
    Sales_record next;
} SALES;
struct receipt_node {
    Receipt receipt;
    Goods_receipt next; 
} GOODS_RECEIPT;

// Function Prototypes
Item_inventory search_item(Item_inventory node, int n);
Item_inventory sort_inventory(Item_inventory head);
Item_inventory add_item(Item_inventory head);
Item_inventory delete_item(Item_inventory head);
Sales_record update_sales(Sales_record sales, Item_inventory *head);
Goods_receipt update_goods_receipt(Goods_receipt receipt, Item_inventory *head);
void display_item(Item_inventory head);
void display_all_items(Item_inventory head);
void display_all_sales(Sales_record sales);
void display_goods_receipt(Goods_receipt receipt);

int main(void) {
    Item_inventory inventory = NULL;
    Sales_record sales_record = NULL;
    Goods_receipt goods_receipt = NULL;
    int choice;

    do {
        system("cls");
        printf("ALVAREZ Enterprise\n");
        printf("1] Add New Item\n");
        printf("2] Delete an Item\n");
        printf("3] Sales\n");
        printf("4] Good Receipt\n");
        printf("5] Display Specific Item\n");
        printf("6] Display All Inventory Items\n");
        printf("7] Display All Sales\n");
        printf("8] Display All Goods Receipt\n");
        printf("9] Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: inventory = add_item(inventory);
                break;
            case 2: inventory = delete_item(inventory);
                break;
            case 3: sales_record = update_sales(sales_record, &inventory);
                break;
            case 4: goods_receipt = update_goods_receipt(goods_receipt, &inventory);
                break;
            case 5: display_item(inventory);
                break;
            case 6: display_all_items(inventory);
                break;
            case 7: display_all_sales(sales_record);
                break;
            case 8: display_goods_receipt(goods_receipt);
                break;
            case 9: printf("Thank You!\n");
                break;
            default: printf("Invalid Choice!\n");
        }
    } while (choice != 9);

    return 0;
}

Item_inventory search_item(Item_inventory node, int n) {
    while (node != NULL) { 
        if (node->item.number == n)  
            return node;
        node = node->next;
    }
    return NULL;
}

Item_inventory sort_inventory(Item_inventory head) {
    Items temp;
    for (Item_inventory i = head; i != NULL; i = i->next) {
        for (Item_inventory j = i->next; j != NULL; j = j->next) {
            if (j->item.number < i->item.number) {
                temp = j->item;
                j->item = i->item;
                i->item = temp;
            }
        }
    }
    return head;
}

Item_inventory add_item(Item_inventory head) {
    system("cls");

    int i_num;
    printf("Add Inventory Item\n");
    printf("Item Number: ");
    scanf("%d", &i_num);

    if (search_item(head, i_num) != NULL) {
        printf("Item Already Exists!\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return head;
    }

    Item_inventory new_item = malloc(sizeof(ITEM));

    new_item->item.number = i_num;
    new_item->next = NULL;
    FLUSH;
    printf("Item Name: ");
    gets(new_item->item.name);
    printf("Quantity: ");
    scanf("%hd", &new_item->item.quantity);
    printf("Selling Price: ");
    scanf("%f", &new_item->item.selling_price);

    Item_inventory tail = head;
    if (head != NULL) 
        while (tail->next != NULL)
            tail = tail->next;

    if (head == NULL) {
        head = new_item;
    } else {
        tail->next = new_item;
    }

    printf("\nPress ENTER to go back to menu...");
    getch();

    head = sort_inventory(head);

    return head;
}

Item_inventory delete_item(Item_inventory head) {
    system("cls");

    int i_num;
    printf("Delete Inventory Item\n");
    printf("Item Number: ");
    scanf("%d", &i_num);

    Item_inventory cur = search_item(head, i_num);
    if (cur == NULL) {
        printf("Invalid! Item does not exit.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return head;
    }

    char op;
    printf("Item Name: %s\n", cur->item.name);
    printf("Continue to delete item (Y/n): ");
    scanf(" %c", &op);
    if (op != 'Y' && op != 'y') {
        printf("\nPress ENTER to go back to menu...");
        getch();
        return head;
    }

    if (cur == head) {  
        head = head->next;
        free(cur);
    } else {
        Item_inventory prev = head;
        
        while (prev->next != cur)
            prev = prev->next;
        prev->next = cur->next;
        free(cur);
    }

    printf("Item Deleted!\n");
    printf("\nPress ENTER to go back to menu...");
    getch();

    return head;
}

Sales_record update_sales(Sales_record sales, Item_inventory *head) {
    system("cls");

    int i_num;
    printf("Update Sales\n");
    printf("Item Number: ");
    scanf("%d", &i_num);

    Item_inventory item = search_item(*head, i_num);
    if (item == NULL) {
        printf("Invalid! Item does not exist.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return sales;
    }

    Item_inventory temp = *head;
    while (temp->item.number != item->item.number)
        temp = temp->next;

    short quantity;
    printf("Quantity Bought: ");
    scanf("%hd", &quantity);

    if (quantity < 0) {
        printf("Invalid Item Quantity!\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return sales;
    }

    if (temp->item.quantity <= 0) {
        printf("Invalid! Item out of stock.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return sales;
    }
    else if (temp->item.quantity < quantity) {
        printf("Invalid! Insufficient stock.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return sales;
    }
    temp->item.quantity -= quantity;

    Sales_record new_sales = malloc(sizeof(SALES));
    new_sales->sales.item_number = temp->item.number;
    new_sales->sales.quantity_bought = quantity;
    new_sales->sales.line_amount = quantity * temp->item.selling_price;
    new_sales->next = NULL;

    FLUSH;
    printf("Date: ");
    gets(new_sales->sales.date);


    Sales_record tail = sales;
    if (sales != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }

    if (sales == NULL) {
        sales = new_sales;
    } else {
        tail->next = new_sales;
    }

    printf("\nPress ENTER to go back to menu...");
    getch();

    return sales;
}

Goods_receipt update_goods_receipt(Goods_receipt receipt, Item_inventory *head) {
    system("cls");

    int i_num;
    printf("Update Goods Receipt\n");
    printf("Item Number: ");
    scanf("%d", &i_num);

    Item_inventory item = search_item(*head, i_num);
    if (item == NULL) {
        printf("Invalid! Item does not exist.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return receipt;
    }

    Item_inventory temp = *head;
    while (temp->item.number != item->item.number)
        temp = temp->next;

    short quantity;
    printf("Quantity Received: ");
    scanf("%hd", &quantity);

    if (quantity < 0) {
        printf("Invalid Item Quantity\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return receipt;
    }
    temp->item.quantity += quantity;

    Goods_receipt new_receipt = malloc(sizeof(GOODS_RECEIPT));
    new_receipt->receipt.item_number = temp->item.number;
    new_receipt->receipt.quantity_delivered = quantity;
    new_receipt->next = NULL;

    FLUSH;
    printf("Date: ");
    gets(new_receipt->receipt.date);

    Goods_receipt tail = receipt;
    if (receipt != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }

    if (receipt == NULL) {
        receipt = new_receipt;
    } else {
        tail->next = new_receipt;
    }

    printf("\nPress ENTER to go back to menu...");
    getch();

    return receipt; 
}

void display_item(Item_inventory head) {
    system("cls");

    int i_num;
    printf("Display Specific Item\n");
    printf("Item Number: ");
    scanf("%d", &i_num);

    Item_inventory item = search_item(head, i_num);
    if (item == NULL) {
        printf("Invalid! Item does not exit.\n");
        printf("\nPress ENTER to go back to menu...");
        getch();
        return;
    }

    printf("Item Name: %s\n", item->item.name);
    printf("Quantity: %hd\n", item->item.quantity);
    printf("Selling Price: %.2f\n", item->item.selling_price);

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void display_all_items(Item_inventory head) {
    system("cls");

    if (head == NULL) {
        printf("Inventory Empty!\n");
        printf("Press ENTER to go back to menu...");
        getch();
        return;
    }

    int i = 1;
    while (head != NULL) {
        printf("[%d]\n", i++);
        printf("Item Number: %d\n", head->item.number);
        printf("Item Name: %s\n", head->item.name);
        printf("Quantity: %hd\n", head->item.quantity);
        printf("Selling Price: %.2f\n", head->item.selling_price);
        head = head->next;
    }

    printf("\nPress ENTER to go back to menu...");
    getch();
}

void display_all_sales(Sales_record sales) {
    system("cls");

    if (sales == NULL) {
        printf("Sales Record Empty!\n");
        printf("Press ENTER to go back to menu...");
        getch();
        return;
    }
    
    int i = 1;
    while (sales != NULL) {
        printf("[%d]\n", i++);
        printf("Date: %s\n", sales->sales.date);
        printf("Item Number: %hd\n", sales->sales.item_number);
        printf("Quantity Bought: %hd\n", sales->sales.quantity_bought);
        printf("Line Amount: %.2f\n", sales->sales.line_amount);
        sales = sales->next;
    }

    printf("\nPress ENTER to go back to menu...");
    getch();
}   

void display_goods_receipt(Goods_receipt receipt) {
    system("cls");

    if (receipt == NULL) {
        printf("Goods Receipt Empty!\n");
        printf("Press ENTER to go back to menu...");
        getch();
        return;
    }
    
    int i = 1;
    while (receipt != NULL) {
        printf("[%d]\n", i++);
        printf("Date: %s\n", receipt->receipt.date);
        printf("Item Number: %hd\n", receipt->receipt.item_number);
        printf("Quantity Delivered: %hd\n", receipt->receipt.quantity_delivered);
        receipt = receipt->next;
    }

    printf("\nPress ENTER to go back to menu...");
    getch();
}