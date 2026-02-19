/*
Modify Programming Project 8 from Chapter 5 so that the departure times are stored in an
array and the arrival times are stored in a second array. (The times are integers, representing
the number of minutes since midnight.) The program will use a loop to search the array of
departure times for the one closest to the time entered by the user.
*/

#include <stdio.h>

#define N 8

int main(void) {
    int hour, minute, time;
    
    printf("Enter a 24-hour time (hh:mm): ");
    scanf("%d:%d", &hour, &minute);
    time = hour * 60 + minute;

    int dep[N] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int arr[N] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    int dep_time, arr_time, i;
    for (i = 0; i < N-1; i++) {
        int midpoint = (dep[i] + arr[i]) / 2;

        if (time <= midpoint) {
            dep_time = dep[i];
            arr_time = arr[i];
            break;
        }
    }

    if (i == N-1) {
        dep_time = dep[N-1];
        arr_time = arr[N-1];
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