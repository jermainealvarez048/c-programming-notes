/*
Printing a One-Month Reminder List

To illustrate the use of the C string library, we’ll now develop a program that prints
a one-month list of daily reminders. The user will enter a series of reminders, with
each prefixed by a day of the month. When the user enters 0 instead of a valid day,
the program will print a list of all reminders entered, sorted by day. Here’s what a
session with the program will look like:
Enter day and reminder: 24 Susan's birthday
Enter day and reminder: 5 6:00 - Dinner with Marge and Russ
Enter day and reminder: 26 Movie - "Chinatown"
Enter day and reminder: 7 10:30 - Dental appointment
Enter day and reminder: 12 Movie - "Dazed and Confused"
Enter day and reminder: 5 Saturday class
Enter day and reminder: 12 Saturday class
Enter day and reminder: 0

Day Reminder
  5 Saturday class
  5 6:00 - Dinner with Marge and Russ
  7 10:30 - Dental appointment
 12 Saturday class
 12 Movie - "Dazed and Confused"
 24 Susan's birthday
 26 Movie - "Chinatown"

    The overall strategy isn’t very complicated: we’ll have the program read a
series of day-and-reminder combinations, storing them in order (sorted by day),
and then display them. To read the days, we’ll use scanf; to read the reminders,
we’ll use the read_line function of Section 13.3.
    We’ll store the strings in a two-dimensional array of characters, with each row
of the array containing one string. After the program reads a day and its associated
reminder, it will search the array to determine where the day belongs, using
strcmp to do comparisons. It will then use strcpy to move all strings below
that point down one position. Finally, the program will copy the day into the array
and call strcat to append the reminder to the day. (The day and the reminder
have been kept separate up to this point.).

    Of course, there are always a few minor complications. For example, we want
the days to be right-justified in a two-character field, so that their ones digits will
line up. There are many ways to handle the problem. I’ve chosen to have the pro
gram use scanf to read the day into an integer variable, then call sprintf to
convert the day back into string form. sprintf is a library function that’s similar
to printf, except that it writes output into a string. The call

sprintf(day_str, "%2d", day);

writes the value of day into day_str. Since sprintf automatically adds a null
character when it’s through writing, day_str will contain a properly null-termi
nated string.
    Another complication is making sure that the user doesn’t enter more than two
digits. We’ll use the following call of scanf for this purpose:

scanf("%2d", &day);

The number 2 between % and d tells scanf to stop reading after two digits, even
if the input has more digits.
    With those details out of the way, here’s the program:
*/

/* Prints a one-month reminder list */
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void) {
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, j, num_remind = 0;
    
    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
    
        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);
        
        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);
        
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        
        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
    
    return 0;
}

int read_line(char str[], int n) {
    int ch, i = 0;
    
    while ((ch = getchar()) != '\n')
        if (i < n)
        str[i++] = ch;
    str[i] = '\0';
    
    return i;
}