/* 
--Selection Sort Algorithm--

- The list is divided into two sublists, the sorted and the 
unsorted, which are divided by an imaginary wall.
- The smallest element from the unsorted sublist is swapped with 
the element at the beginning of the unsorted list.
- After each swap, the imaginary wall is moved one element ahead.
*/

#include <stdio.h>

#define N 10

void selection_sort(int arr[], int size);
void output_arr(int arr[], int size);

int main(void) {
    int a[N] = {4, 6, 1, 10, 8, 2, 9, 7, 3, 5};

    // sort array using selection sort algorithm
    selection_sort(a, N);

    // output array
    output_arr(a, N);

    return 0;
}

void selection_sort(int arr[], int size) {
    int i, j, smallest, temp;

    for (i = 0; i < size - 1; i++) {
        smallest = i;
        for (j = i + 1; j < size; j++)
            if (arr[j] < arr[smallest])
                smallest = j;
        temp = arr[i]; 
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}

void output_arr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}