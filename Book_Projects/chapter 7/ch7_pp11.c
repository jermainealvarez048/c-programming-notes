/* 
Write a program that takes a first name and last name entered by the user and displays the
last name, a comma, and the first initial, followed by a period:

Enter a first and last name: Lloyd Fosdick
Fosdick, L.

The user’s input may contain extra spaces before the first name, between the first and last
names, and after the last name. */

#include <stdio.h>

int main(void)
{
    char c, name_initial;

    printf("Enter a first and last name: ");

    while ((c = getchar()) == ' ')
        ;

    name_initial = c;
    
    while ((c = getchar()) != ' ' && c != '\n')
        ;

    while (c == ' ') {
        c = getchar();
    }

    while (c != ' ' && c != '\n') {
        putchar(c);
        c = getchar();
    }

    printf(", %c.\n", name_initial);

    return 0;
}