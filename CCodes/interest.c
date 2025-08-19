/*
Computing Interest

Our next program prints a table showing the value of $100 invested at different
rates of interest over a period of years. The user will enter an interest rate and the
number of years the money will be invested. The table will show the value of the
money at one-year intervals—at that interest rate and the next four higher rates—
assuming that interest is compounded once a year. Here’s what a session with the
program will look like:

Enter interest rate: 6
Enter number of years: 5

Years     6%     7%     8%     9%    10%
 1     106.00 107.00 108.00 109.00 110.00
 2     112.36 114.49 116.64 118.81 121.00
 3     119.10 122.50 125.97 129.50 133.10
 4     126.25 131.08 136.05 141.16 146.41
 5     133.82 140.26 146.93 153.86 161.05

Clearly, we can use a for statement to print the first row. The second row is a
little trickier, since its values depend on the numbers in the first row. Our solution
is to store the first row in an array as it’s computed, then use the values in the array
to compute the second row. Of course, this process can be repeated for the third
and later rows. We’ll end up with two for statements, one nested inside the other.
The outer loop will count from 1 to the number of years requested by the user. The
inner loop will increment the interest rate from its lowest value to its highest value.
*/

/* Prints a table of compund interest*/

#include <stdio.h>
#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void) {
    int i, low_rate, num_years, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++) {
            value[i] += (low_rate + i) / 100.0 * value[i];
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    return 0;
}