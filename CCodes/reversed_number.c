#include <stdio.h>

int main(void)
{
    int number, original, reversed = 0;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (number <= 0) {
        printf("Error! Please enter a non-zero integer.\n");
        return 1;
    }

    original = number;

    while (number != 0) {
        reversed = reversed * 10 + number % 10;
        number = number / 10;
    }

    printf("Reversed: %d\n", reversed);

    if (reversed == original) {
        printf("The number is a palindrome!\n");
    }

    return 0;
}