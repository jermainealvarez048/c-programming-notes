/*
Modify Programming Project 4 from Chapter 7 so that the program labels its output:

Enter phone number: 1-800-COL-LECT
In numeric form: 1-800-265-5328

The program will need to store the phone number (either in its original form or in its
numeric form) in an array of characters until it can be printed. You may assume that the
phone number is no more than 15 characters long.
*/

#include <ctype.h>
#include <stdio.h>

#define N 15

int main(void) {
    char number[N];
    char ch;
    
    printf("Enter phone number: ");
    int len = 0;
    while ((ch = getchar()) != '\n' && len < N) {
        char upper = toupper(ch);
        switch(upper) {
            case 'A': case 'B': case 'C': upper = '2'; break;
            case 'D': case 'E': case 'F': upper = '3'; break;
            case 'G': case 'H': case 'I': upper = '4'; break;
            case 'J': case 'K': case 'L': upper = '5'; break;
            case 'M': case 'N': case 'O': upper = '6'; break;
            case 'P': case 'R': case 'S': upper = '7'; break;
            case 'T': case 'U': case 'V': upper = '8'; break;
            case 'W': case 'X': case 'Y': upper = '9'; break;
        }
        number[len++] = upper;
    }

    number[len] = '\0';

    printf("In numeric form: %s\n", number);

    return 0;
}