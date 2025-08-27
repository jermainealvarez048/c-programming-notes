/* Insertion of an Element at specified position in an Array */

#include <stdio.h>

#define N 5

int main(void) {
    int array[N];
    int position; // where the value is to be inserted
    int element; // which value to be inserted

    for (int i = 0; i < N; i++)
        scanf("%d", &array[i]);
    
    scanf("%d", &position);
    scanf("%d", &element);

    for (int i = N-1; i >= position; i--)
        array[i+1] = array[i];
    array[position] = element;
    
    for (int i = 0; i <= N; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}