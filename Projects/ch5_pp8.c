/* The following table shows the daily flights from one city to another:
    Departure time  Arrival time
    8:00 a.m.       10:16 a.m.
    9:43 a.m.       11:52 a.m.
    11:19 a.m.       1:31 p.m.
    12:47 p.m.       3:00 p.m
     2:00 p.m.       4:08 p.m.
     3:45 p.m.       5:55 p.m.
     7:00 p.m.       9:20 p.m.
     9:45 p.m.      11:58 p.m.

Write a program that asks user to enter a time (expressed in hours and minutes, using the 24-
hour clock). The program then displays the departure and arrival times for the flight whose
departure time is closest to that entered by the user:

Enter a 24-hour time: 13:15
Closest departure time is 12:47 p.m., arriving at 3:00 p.m.

Hint: Convert the input into a time expressed in minutes since midnight, and compare it to
the departure times, also expressed in minutes since midnight. For example, 13:15 is 13 ×
60 + 15 = 795 minutes since midnight, which is closer to 12:47 p.m. (767 minutes since
midnight) than to any of the other departure times. */

#include <stdio.h>

int main(void) 
{
    int hour, minute, time;

    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hour, &minute);
    time = hour * 60 + minute;

    int dep1 = 480;
    int dep2 = 583;
    int dep3 = 679;
    int dep4 = 767;
    int dep5 = 840;
    int dep6 = 945;
    int dep7 = 1140;
    int dep8 = 1305;

    int arr1 = 616;
    int arr2 = 712;
    int arr3 = 811;
    int arr4 = 900;
    int arr5 = 968;
    int arr6 = 1075;
    int arr7 = 1280;
    int arr8 = 1438;

    int dep_time, arr_time;

    if (time <= (dep1 + dep2) / 2) {
        dep_time = dep1;
        arr_time = arr1;
    }
    else if (time <= (dep2 + dep3) / 2) {
        dep_time = dep2;
        arr_time = arr2;
    }
    else if (time <= (dep3 + dep4) / 2) {
        dep_time = dep3;
        arr_time = arr3;
    }
    else if (time <= (dep4 + dep5) / 2) {
        dep_time = dep4;
        arr_time = arr4;
    }
    else if (time <= (dep5 + dep6) / 2) {
        dep_time = dep5;
        arr_time = arr5;
    }
    else if (time <= (dep6 + dep7) / 2) {
        dep_time = dep6;
        arr_time = arr6;
    }
    else if (time <= (dep7 + dep8) / 2) {
        dep_time = dep7;
        arr_time = arr7;
    } else {
        dep_time = dep8;
        arr_time = arr8;
    }

    int dep_h = dep_time / 60;
    int dep_m = dep_time % 60;
    int arr_h = arr_time / 60;
    int arr_m = arr_time % 60;
 
    int dep_display_hour, arr_display_hour;
    char dep_meridiem, arr_meridiem;


    if (dep_h == 0) {
        dep_display_hour = 12;
        dep_meridiem = 'a';
    } 
    else if (dep_h < 12) {
        dep_display_hour = dep_h;
        dep_meridiem = 'a';
    } 
    else if (dep_h == 12) {
        dep_display_hour = 12;
        dep_meridiem = 'p';
    } else {
        dep_display_hour = dep_h - 12;
        dep_meridiem = 'p';
    }

    if (arr_h == 0) {
        arr_display_hour = 12;
        arr_meridiem = 'a';
    } 
    else if (arr_h < 12) {
        arr_display_hour = arr_h;
        arr_meridiem = 'a';
    } 
    else if (arr_h == 12) {
        arr_display_hour = 12;
        arr_meridiem = 'p';
    } else {
        arr_display_hour = arr_h - 12;
        arr_meridiem = 'p';
    }

    printf("Closest departure time is %d:%02d %c.m, arriving at %d:%02d %c.m.\n", 
        dep_display_hour, dep_m, dep_meridiem, arr_display_hour, arr_m, arr_meridiem);

    

    return 0;
}