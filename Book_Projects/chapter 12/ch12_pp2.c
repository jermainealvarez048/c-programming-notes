/*
(a) Write a program that reads a message, then checks whether it’s a palindrome (the letters
in the message are the same from left to right as from right to left):
Enter a message: He lived as a devil, eh?
Palindrome
Enter a message: Madam, I am Adam.
Not a palindrome
Ignore all characters that aren’t letters. Use integer variables to keep track of positions in the
array.
(b) Revise the program to use pointers instead of integers to keep track of positions in the
array.
*/

#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>

#define N 80

int main(void) {
    char message[N];
    char ch, *p = message, *q = message;

    printf("Enter a message: ");
    while (p < message + N && (ch = getchar()) != '\n') 
        if (isalpha(ch))
            *p++ = toupper(ch);
    p--;
    
    bool is_palindrome = true;
    while (p >= q) {
        if ((*p--) != (*q++)) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome)
        printf("Palindrome\n");
    else    
        printf("Not a palindrome\n");

    return 0;
}