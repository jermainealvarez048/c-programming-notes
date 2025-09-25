/* Insertion of an element at specified position in an Array */

#include <stdio.h>

#define N 5

int main(void) {
    int A[N];
    int position, element, i;

    printf("Enter 5 numbers: ");
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    
    printf("Enter position: ");
    scanf("%d", &position);
    printf("Enter element: ");
    scanf("%d", &position);

    return 0;
}