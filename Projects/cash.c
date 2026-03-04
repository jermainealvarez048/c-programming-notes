/* Cash - Greedy Algorithm */

#include <stdio.h>

int calculate_quarters(int n);
int calculate_dimes(int n);
int calculate_nickels(int n);
int calculate_pennies(int n);

int main(void) {
    int cents;

    // Prompt the user for change owed, in cents
    do {
        printf("Change owed: ");
        scanf("%d", &cents);
    } while (cents < 0);

    // Calculate how many quarters you should give customer
    // Subtract the value of those quarters from cents
    int quarters = calculate_quarters(cents);
    cents %= 25;

    // Calculate how many dimes you should give customer
    // Subtract the value of those dimes from remaining cents
    int dimes = calculate_dimes(cents);
    cents %= 10;

    // Calculate how many nickels you should give customer
    // Subtract the value of those nickels from remaining cents
    int nickels = calculate_nickels(cents);
    cents %= 5;

    // Calculate how many pennies you should give customer
    // Subtract the value of those pennies from remaining cents
    int pennies = calculate_pennies(cents);
    cents %= 1;

    // Sum the number of quarters, dimes, nickels, and pennies used
    // Print that sum
    int sum = quarters + dimes + nickels + pennies;
    printf("%d\n", sum);

    return 0;
}

int calculate_quarters(int n) {
    return n / 25;
    /*
    or: 
    int quarters = 0;
    while (n >= 25) {
        quarters++;
        n -= 25;
    }

    return quarters;
    */
}

int calculate_dimes(int n) {
    return n / 10;
}

int calculate_nickels(int n) {
    return n / 5;
}

int calculate_pennies(int n) {
    return n / 1;
}