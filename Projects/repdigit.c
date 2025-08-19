/*
Checking a Number for Repeated Digits

Our next program checks whether any of the digits in a number appear more than once. After 
the user enters a number, the program prints either Repeated digit or No repeated digit:

Enter a number: 28212
Repeated digit

The number 28212 has a repeated digit (2); a number like 9357 doesn’t. The program uses 
an array of Boolean values to keep track of which digits appear in a number. The array, 
named digit_seen, is indexed from 0 to 9 to correspond to the 10 possible digits. Initially, 
every element of the array is false. (The initializer for digit_seen is {false}, which only 
initializes the first element of the array. However, the compiler will automatically make 
the remaining elements zero, which is equivalent to false.)

When given a number n, the program examines n’s digits one at a time, storing each into 
the digit variable and then using it as an index into digit_seen. If digit_seen[digit] is 
true, then digit appears at least twice in n. On the other hand, if digit_seen[digit] is 
false, then digit has not been seen before, so the program sets digit_seen[digit] to true 
and keeps going.
*/

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool digit_seen[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            break;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    if (n > 0) {
        printf("Repeated digit\n");
    } else {
        printf("No repeated digit\n");
    }

    return 0;
}