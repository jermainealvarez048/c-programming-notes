/*
Write a program that asks the user to enter a series of integers (which it stores in an array),
then sorts the integers by calling the function selection_sort. When given an array
with n elements, selection_sort must do the following:
1. Search the array to find the largest element, then move it to the last position in the array.
2. Call itself recursively to sort the first n – 1 elements of the array.
*/

#include <stdio.h>

#define N 10

void selection_sort(int arr[], int n);

int main(void) {
    int a[N] = {6, 10, 1, 2, 8, 9, 3, 5, 7, 4};

    selection_sort(a, N-1);

    for (int i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void selection_sort(int arr[], int n) {
    int i, largest, temp;

    if (n == 0)
        return;

    largest = 0;
    for (i = 1; i <= n; i++)
        if (arr[i] > arr[largest])
            largest = i;
    temp = arr[n];
    arr[n] = arr[largest];
    arr[largest] = temp;
    selection_sort(arr, n-1);
}