/* Write a program that asks the user for a 12-hour time, then displays the time in 24-hour
form:
Enter a 12-hour time: 9:11 PM
Equivalent 24-hour time: 21:11 
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, minute, time;
    char meridiem1, meridiem2;

    printf("Enter a 12-hour time (hh:mm AM/PM): ");
    scanf("%d:%d", &hour, &minute);
    
    while (getchar() == '\n') {
        printf("Error! Invalid Input.\n");
        return 1;
    }

    while ((meridiem1 = getchar()) == ' ');
    meridiem1 = toupper(meridiem1);

    meridiem2 = getchar();
    if (meridiem2 == '\n') {
        meridiem2 = 'M';
    } else {
        meridiem2 = toupper(meridiem2);
    }
    
    if (hour > 12 || minute > 60 || (meridiem1 != 'A' && meridiem1 != 'P') || meridiem2 != 'M') {
        printf("Error! Invalid Input.\n");
        return 1;
    }

    if (meridiem1 == 'A' && hour == 0) {
        hour += 12;
    }
    else if (meridiem1 == 'P') {
        hour += 12;
    }

    if (hour == 24 && minute > 0) {
        hour -= 24;
    }

    printf("Equivalent 24-hour time: %02d:%02d\n", hour, minute);



    return 0;
}

