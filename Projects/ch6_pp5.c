/*
Programming Project 1 in Chapter 4 asked you to write a program that displays a two-digit
number with its digits reversed. Generalize the program so that the number can have one,
two, three, or more digits. Hint: Use a do loop that repeatedly divides the number by 10,
stopping when it reaches 0.
*/

#include <stdio.h>

int main(void)
{
    int i;

    printf("Enter a number: ");
    scanf("%d", &i); 

    printf("The reversal is: ");

    do {
        printf("%d", i % 10);
        i = i / 10;
    } while (i != 0);

    printf("\n");

    return 0;
}