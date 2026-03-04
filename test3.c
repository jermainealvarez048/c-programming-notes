#include <stdio.h>

void change(int **pp);

int main(void) {
    int arr[3] = {1, 2, 3};
    int *p = arr;

    change(&p);

    printf("%d\n", *p);
    
    return 0;
}

void change(int **pp) {
    pp = pp + 1;
}