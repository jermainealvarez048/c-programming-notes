/*
Modify the repdigit.c program of Section 8.1 so that it shows which digits (if any)
were repeated:
Enter a number: 939577
Repeated digit(s): 7 9
*/

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool digit_seen[10] = {false};
    bool digit_repeated[10] = {false};
    bool any_digit_repeated = false;
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            digit_repeated[digit] = true;
            any_digit_repeated = true;
        }
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("Repeated digit(s):");
    for (int digit = 0; digit < 10; digit++) {
        if (digit_repeated[digit]) 
            printf(" %d", digit);
    }

    if (!any_digit_repeated) printf(" none");
    printf("\n");

    return 0;
}