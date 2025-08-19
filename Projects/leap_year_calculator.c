/*
📅 Leap Year Calculator & Day Counter
Situation:
Ask the user for a year and a month number.
Determine if the year is a leap year and how many days are in that month.
Example:
Enter year: 2024
Enter month number (1-12): 2

Leap year: Yes
Days in month: 29
*/

#include <stdio.h>

int main(void)
{
	int year, month;
    int leap_year = 0;
	int days_in_month = 0;

	printf("Enter a year: ");
	scanf("%d", &year);

    printf("Enter month number (1-12): ");
    scanf("%d", &month);	

	if (month < 1 || month > 12 || year < 1) {
		printf("Error! Invalid Input.\n");
		return 1;
	}

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
		leap_year = 1;
	}

	switch (month) {
		case 1: case 3: case 5: case 7: 
		case 8: case 10: case 12:
			days_in_month = 31;
			break;
		case 4: case 6: case 9: case 11:
			days_in_month = 30;
			break;
		case 2:
			days_in_month = leap_year ? 29 : 28;
			break;
	}

	printf("Leap year: ");
	if (leap_year) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}

	printf("Days in month: %d\n", days_in_month);
	
	return 0;
}