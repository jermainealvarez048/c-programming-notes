/* Sorting numbers */

#include <stdio.h>

int main(void) {
    int num[10];
    int temp;

    printf("Enter 10 numbers         : ");
    for (int i = 0; i < 10; i++) 
        scanf("%d", &num[i]);
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (num[i] < num[j]) {
                temp = num[j];
                num[j] = num[i];
                num[i] = temp;
            }
        }
    }

    printf("lowest to greatest number:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", num[i]);
    }
    printf("\n");

    return 0;
}