// Floyd Triangle

#include <stdio.h>

int main(void)
{
    int rows;
    int i, j;
    int numbers = 1;
    int next_line = 1;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        for (j = 1; j <= i; j++) {
            printf("%2d ", numbers);
            numbers++;

        }
        printf("\n");
    }

    return 0;
}