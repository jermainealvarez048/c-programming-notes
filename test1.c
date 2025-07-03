#include <stdio.h>

int main(void)
{
    int a[10], i;

    for (i = 1; i <= 10; i++) {
        a[i] = 1;
        printf("%d = %d\n", i, a[i]);
    }

    return 0;
}   