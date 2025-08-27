/* find the largest and smallest number */

#include <stdio.h>

#define NUM_SIZE ((int) (sizeof(num) / sizeof(num[0])))

int main(void) {
    int num[5];
    int largest, smallest;

    printf("Enter 5 numbers: ");
    for (int i = 0; i < NUM_SIZE; i++)
        scanf("%d", &num[i]);

    largest = num[0];
    smallest = num[0];

    for (int i = 1; i < NUM_SIZE; i++) {
        if (num[i] > largest) 
            largest = num[i];
        if (num[i] < smallest)
            smallest = num[i];
    }

    printf("Largest number: %d\n", largest);
    printf("Smallest number: %d\n", smallest);

    return 0;
}