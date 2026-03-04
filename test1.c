#include <stdio.h>
#include <stdlib.h>

typedef struct node *ndPtr;
struct node {
    int data;
    ndPtr next;
} NODE;

int main(void) {
    ndPtr new_code, head, tail;
    new_code = head = tail = NULL;

    char ch;
    int value = 10, n = 0;
    
    do {
        new_code = malloc(sizeof(NODE));
        new_code->data = value;
        new_code->next = NULL;
        if (head == NULL) {
            head = new_code;
            tail = new_code;
        } else {
            tail->next = new_code;
            tail = new_code;
        }

        n++;
        value += 10;
    } while (n != 5);

    // delete at beginning
    /*ndPtr temp1 = head;
    head = head->next;
    free(temp1);
    */

    // delete at last
    /*ndPtr temp1, prev;
    temp1 = head;
    while (temp1->next != NULL) {
        prev = temp1;
        temp1 = temp1->next;
    }
    prev->next = NULL;
    free(temp1);
    */

    // delete node between the first and last
    ndPtr temp = head;
    int position = 2;
    for (int i = 0; i < position - 1; i++)
        temp = temp->next;
    temp->next = temp->next->next;


    ndPtr temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
