#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **q = &p;

    printf("%d\n", **q);

    return 0;
}