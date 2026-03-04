/*
Write a function named censor that modifies a string by replacing every occurrence of
foo by xxx. For example, the string "food  fool" would become "xxxd  xxxl". Make
the function as short as possible without sacrificing clarity.
*/

#include <stdio.h>

#define STR_LEN 50

int read_line(char str[], int n);
void censor(char *str);

int main(void) {
    char message[STR_LEN+1];

    printf("Enter message: ");
    int message_len = read_line(message, STR_LEN);
    censor(message);

    printf("Message: %s\n", message);

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

/*
void censor(char *str) {
    while (*(str + 2) != '\0') {
        if (*str == 'f' && *(str+1) == 'o' && *(str+2) == 'o') {
            *str = *(str+1) = *(str+2) = 'x';
            str = str + 2;
        } else {
            str++;
        }
    }
} 
*/

/*
or 
*/

void censor(char *str) {
    for (; *str != '\0'; str++)
        if (*str == 'f' && *(str+1) == 'o' && *(str+2) == 'o')
            *str = *(str+1) = *(str+2) = 'x';
}