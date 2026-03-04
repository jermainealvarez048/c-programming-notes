/*
Credit: Luhn's Algorithm
1. card starts with:
- for this program...
American Express -> 34 or 37 (15 digits)
Mastercard       -> 51, 52, 53, 54, or 55 (16 digits)
Visa             -> 4 (13 0r 16 digits)

2. checksum -> luhn's algorithm
    1. multiply every other digit by 2, starting with second-to-last digit -> add individual digit together
    2. add sum to (sum of the digits that weren't mulitplied by 2)
    3. if the last's digit is 0 (n % 10 == 0) -> valid

example:
num: 4003600000000014
1. 10000604
    - (1 * 2) + (0 * 2) + (0 * 2) + (0 * 2) + (0 * 2) + ((6 * 2)) + (0 * 2) + (4 * 2)
        = 2 + 0 + 0 + 0 + 0 + (1 + 2) + 0 + 8 -> sum1(13)
    - sum1(13) + sum2(4 + 0 + 0 + 0 + 0 + 0 + 3 + 0) -> sum1(13) + sum2(7) = total(20)
    = valid = total(20) % 10 == 0 // valid
*/

#include <stdbool.h>
#include <stdio.h>

int main(void) {
    long long num;
    int result;

    // prompt for input
    do {
        printf("Number: ");
        result = scanf("%lld", &num);

        if (result != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
    } while (result != 1 || num < 1);

    long long temp_num1 = num;

    // calculate the checksum
    int sum = 0;
    int position = 0;
    int length = 0;

    while (temp_num1 > 0) {
        int digit = temp_num1 % 10;

        if (position % 2 == 1) {
            int product = digit * 2;
            sum += product / 10 + product % 10;
        } else {
            sum += digit;
        }

        temp_num1 /= 10;
        position++;
        length++;
    }

    bool is_valid = false;

    if (sum % 10 == 0) 
        is_valid = true;

    // check for card length and starting digits
    long long temp_num2 = num;
    while (temp_num2 >= 100) {
        temp_num2 /= 10;
    }

    int first_two = temp_num2;
    int first_one = temp_num2 / 10;

    // print AMEX, MASTERCARD, VISA, or INVALID
    if (!is_valid) {
        printf("INVALID\n");
        return 0;
    }

    if (length == 15 && (first_two == 34 || first_two == 37))
        printf("AMEX\n");
    else if (length == 16 && (first_two >= 51 && first_two <= 55))
        printf("MASTERCARD\n");
    else if ((length == 13 || length == 16) && first_one == 4)
        printf("VISA\n");
    else
        printf("INVALID\n");

    return 0;
}