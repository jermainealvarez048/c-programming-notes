#include <stdio.h>

int main(void)
{
    int i = 1;
    int j = 1;

    for (i = 2; j > 0; j--) {
        printf("Inside: %d\n", i);
    }

    printf("Outside: %d\n", i);

    return 0;
}