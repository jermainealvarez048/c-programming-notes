/* Linear Search (Sequential Search)*/

#include <stdio.h>

#define N 5

int enter_key(void);
int linear_search(int arr[], int size, int key);

int main(void) {
    int a[N] = {10, 20, 30, 40, 50};
    int key, index = 0;

    key = enter_key();
    index = linear_search(a, N, key);

    if (index >= 0) {
        printf("Key found\n");
        printf("At index %d\n", index);
    }
    else
        printf("Key not found\n");

    return 0;
}

int enter_key(void) {
    int key; 

    printf("Enter key: ");
    scanf("%d", &key);

    return key;
}

int linear_search(int arr[], int size, int key) {
    int i;
    
    for (i = 0; i < size; i++) {
        if (key == arr[i]) {
            return i; 
        }
    }

    return -1;
}