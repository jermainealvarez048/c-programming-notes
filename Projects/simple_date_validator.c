/*
📅 Project 2: Simple Date Validator
Situation:
Write a program that accepts a day, month, and year as integers and tells whether the date is valid or not.

Requirements:
- Account for months with 30 or 31 days
- Handle February (with 28 or 29 days, depending on leap year)
- Print "Valid Date" or "Invalid Date"

Example:
Enter day: 29
Enter month: 2
Enter year: 2024
Valid Date
*/

#include <stdio.h>

int main(void)
{
    int day, month, year;
    int leap_year = 0;
    int valid_date = 0;

    printf("Enter day: ");
    scanf("%d", &day);

    printf("Enter month: ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    if (year >= 1 && month <= 12 && month >= 1) {
        
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            leap_year = 1;
        }

        switch (month) {
            case 1: case 3: case 5: case 7:
            case 8: case 10: case 12:
                valid_date = (day <= 31 && day >= 1) ? 1 : 0;
                break;
            case 4: case 6: case 9: case 11:
                valid_date = (day <= 30 && day >= 1) ? 1 : 0;
                break;
            case 2:
                if (leap_year) {
                    valid_date = (day <= 29 && day >= 1) ? 1 : 0;
                } else {
                    valid_date = (day <= 28 && day >= 1) ? 1 : 0;
                }
                break;
        }
    }

    if (valid_date) {
        printf("Valid Date\n");
    } else {
        printf("Invalid Date\n");
    }

    return 0;
}