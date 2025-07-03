/*
🔢 Project: Digit Frequency Counter (1–9 only)
🟨 Situation:
You’re building a simple tool that counts how many non-zero digits (1–9 only) appear in a positive integer.

📋 Requirements:
- Ask the user to enter a positive integer
- Count how many times each digit 1–9 appears
- Ignore zeros (0)
- Print how many times each digit occurred

🧪 Example Input/Output:
Input:
Enter a positive integer: 9123341115

Output:
Digit 1: 3 time(s)
Digit 2: 1 time(s)
Digit 3: 2 time(s)
Digit 4: 1 time(s)
Digit 5: 1 time(s)
Digit 9: 1 time(s)

(Only print digits that appear at least once)
*/

#include <stdio.h>

int main(void)
{
    long n;
    int digit;
    int d1 = 0, d2 = 0, d3 = 0, d4 = 0, d5 = 0;
    int d6 = 0, d7 = 0, d8 = 0, d9 = 0;

    printf("Enter a positive integer (1-9): ");
    scanf("%ld", &n);

    if (n <= 0) {
        printf("Error! Enter positive integers only.\n");
        return 1;
    }

    while (n > 0) {
        digit = n % 10;

        switch (digit) {
            case 1: d1++; break;
            case 2: d2++; break;
            case 3: d3++; break;
            case 4: d4++; break;
            case 5: d5++; break;
            case 6: d6++; break;
            case 7: d7++; break;
            case 8: d8++; break;
            case 9: d9++; break;
        }
        
        n /= 10;
    }   
    
    if (d1) printf("Digit 1: %d time%c\n", d1, d1 == 1 ? '\0' : 's');
    if (d2) printf("Digit 2: %d time%c\n", d2, d2 == 1 ? '\0' : 's');
    if (d3) printf("Digit 3: %d time%c\n", d3, d3 == 1 ? '\0' : 's');
    if (d4) printf("Digit 4: %d time%c\n", d4, d4 == 1 ? '\0' : 's');
    if (d5) printf("Digit 5: %d time%c\n", d5, d5 == 1 ? '\0' : 's');
    if (d6) printf("Digit 6: %d time%c\n", d6, d6 == 1 ? '\0' : 's');
    if (d7) printf("Digit 7: %d time%c\n", d7, d7 == 1 ? '\0' : 's');
    if (d8) printf("Digit 8: %d time%c\n", d8, d8 == 1 ? '\0' : 's');
    if (d9) printf("Digit 9: %d time%c\n", d9, d9 == 1 ? '\0' : 's');

    return 0;
}