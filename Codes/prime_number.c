// Check if the number entered by the user is a prime number.

#include <stdio.h>

int main(void)
{
    int n, i, prime_number = 1;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) {
        prime_number = 0;
    } else {
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                prime_number = 0;
                break;
            }
        }
    }

    if (prime_number) {
        printf("%d is a prime number.\n", n);
    } else {
        printf("%d is not a prime number.\n", n);
    }

    return 0;
}