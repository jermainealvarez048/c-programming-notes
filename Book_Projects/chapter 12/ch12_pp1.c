/*
(a) Write a program that reads a message, then prints the reversal of the message:
Enter a message: Don't get mad, get even.
Reversal is: .neve teg ,dam teg t'noD
Hint: Read the message one character at a time (using getchar) and store the characters in
an array. Stop reading when the array is full or the character read is '\n'.
(b) Revise the program to use a pointer instead of an integer to keep track of the current
position in the array.
*/

#include <stdio.h>

#define N 80

int main(void) {
    char m[N], ch;
    char *p = m;

    printf("Enter a message: ");
    while (p < m + N && (ch = getchar()) != '\n')
        *p++ = ch;
    
    printf("Reversal is: ");
    p--;
    while (p >= m) 
        putchar(*p--);
    printf("\n");

    return 0;
}