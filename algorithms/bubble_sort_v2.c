/*
--Bubble Sort Algorithm--

- The smallest element is bubbled from the unsorted sublist and 
moved to the sorted sublist. 
- The bubbling process is done in the inner loop
*/

#include <stdio.h>

#define N 10

void bubble_sort(int arr[], int size);
void output_arr(int arr[], int size);

int main(void) {
    int a[N] = {4, 6, 1, 10, 8, 2, 9, 7, 3, 5};

    // sort array using bubble sort algorithm
    bubble_sort(a, N);

    // output array
    output_arr(a, N);

    return 0;
}

void bubble_sort(int arr[], int size) {
    int temp, i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = size - 1; j > i; j++) {
            if (arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

void output_arr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}