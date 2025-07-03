/* Modify Programming Project 8 from Chapter 5 so that the user enters a time using the 12-
hour clock. The input will have the form hours:minutes followed by either A, P, AM, or PM
(either lower-case or upper-case). White space is allowed (but not required) between the
numerical time and the AM/PM indicator. Examples of valid input:
1:15P
1:15PM
1:15p
1:15pm
1:15 P
1:15 PM
1:15 p
1:15 pm

You may assume that the input has one of these forms; there is no need to test for errors.*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{   
    int hour, minute, time;
    char meridiem1, meridiem2;

    printf("Enter a 12-hour time (hh:mm AM/PM): ");
    scanf("%d:%d", &hour, &minute);

    while ((meridiem1 = getchar()) == ' '); 
    meridiem1 = toupper(meridiem1);

    meridiem2 = getchar();
    if (meridiem2 == '\n') {
        meridiem2 = 'M';
    } else {
        meridiem2 = toupper(meridiem2);
    }

    if (hour > 12 || minute > 59 || (meridiem1 != 'A' && meridiem1 != 'P') || meridiem2 != 'M') {
        printf("Error! Invalid Input!\n");
        return 1;
    }

    if (meridiem1 == 'P' && hour != 12)
        hour += 12;
    else if (meridiem1 == 'A' && hour == 12)
        hour = 0;

    time = hour * 60 + minute;

    int dep1 = 480,  arr1 = 616;
    int dep2 = 583,  arr2 = 712;
    int dep3 = 679,  arr3 = 811;
    int dep4 = 767,  arr4 = 900;
    int dep5 = 840,  arr5 = 968;
    int dep6 = 945,  arr6 = 1075;
    int dep7 = 1140, arr7 = 1280;
    int dep8 = 1305, arr8 = 1438;

    int dep_time, arr_time;

    if (time <= (dep1 + dep2) / 2) {
        dep_time = dep1; arr_time = arr1;
    } else if (time <= (dep2 + dep3) / 2) {
        dep_time = dep2; arr_time = arr2;
    } else if (time <= (dep3 + dep4) / 2) {
        dep_time = dep3; arr_time = arr3;
    } else if (time <= (dep4 + dep5) / 2) {
        dep_time = dep4; arr_time = arr4;
    } else if (time <= (dep5 + dep6) / 2) {
        dep_time = dep5; arr_time = arr5;
    } else if (time <= (dep6 + dep7) / 2) {
        dep_time = dep6; arr_time = arr6;
    } else if (time <= (dep7 + dep8) / 2) {
        dep_time = dep7; arr_time = arr7;
    } else {
        dep_time = dep8; arr_time = arr8;
    }

    int dep_h = dep_time / 60, dep_m = dep_time % 60;
    int arr_h = arr_time / 60, arr_m = arr_time % 60;

    char dep_meridiem = (dep_h >= 12) ? 'p' : 'a';
    char arr_meridiem = (arr_h >= 12) ? 'p' : 'a';
    if (dep_h == 0) dep_h = 12;
    else if (dep_h > 12) dep_h -= 12;
    if (arr_h == 0) arr_h = 12;
    else if (arr_h > 12) arr_h -= 12;

    printf("Closest departure time is %d:%02d %c.m, arriving at %d:%02d %c.m.\n", 
        dep_h, dep_m, dep_meridiem, arr_h, arr_m, arr_meridiem);

    return 0;
}
