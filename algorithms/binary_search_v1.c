/* Binary Search Algorithm in C 
- all elements must be in assorted order
*/

#include <stdio.h>

#define N 10

int binary_search(int arr[], int size, int key);

int main(void) {
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key, index = 0;

    printf("Enter key: ");
    scanf("%d", &key);

    index = binary_search(a, N, key);

    if (index != -1)
        printf("Key found at %d\n", index);
    else 
        printf("Key not found\n");

    return 0;
}

int binary_search(int arr[], int size, int key) {
    int low, mid, high;

    low = 0;
    high = size - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (key == arr[mid]) 
            return mid;
        else if (key > arr[mid]) 
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}