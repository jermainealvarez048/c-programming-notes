/* Binary Search */

#include <stdio.h>

#define N 10

void binary_search(int arr[], int size, int key, int *lcn);

int main(void) {
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key, index;

    printf("Enter key: ");
    scanf("%d", &key);

    binary_search(a, N, key, &index);

    if (index != -1)
        printf("Key found at index %d\n", index);
    else    
        printf("Key not found\n");

    return 0;
}

void binary_search(int arr[], int size, int key, int *lcn) {
    int low, mid, high;

    low = 0;
    high = size - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (key > arr[mid])
            low = mid + 1;
        else if (key < arr[mid])
            high = mid - 1;
        else 
            break;
    }
    *lcn = mid;
}