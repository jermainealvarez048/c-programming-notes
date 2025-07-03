/* 
Write a program that evaluates an expression:

Enter an expression: 1+2.5*3
Value of expression: 10.5

The operands in the expression are floating-point numbers; the operators are +, -, *, and /.
The expression is evaluated from left to right (no operator takes precedence over any other
operator).
*/

#include <stdio.h>

int main(void)
{
    double total, f2;
    char ch;

    printf("Enter an expression: ");
    scanf("%lf", &total);

    while ((ch = getchar()) != '\n') {
        scanf("%lf", &f2);

        switch (ch) {
            case '+':
                total += f2;
                break;
            case '-':
                total -= f2;
                break;
            case '*':
                total *= f2;
                break;
            case '/':
                total /= f2;
                break;
        }
    }

    printf("Value of expression: %.1f\n", total);

    return 0;
}