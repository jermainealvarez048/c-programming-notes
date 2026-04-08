#include <stdio.h>

#define MSG_LEN 50

void read_line(char s[], int len);

int main(void) {
    char message[MSG_LEN+1];

    printf("Enter message: ");
    read_line(message, MSG_LEN);

    printf("\nYour message: %s\n", message);

    return 0;
}

void read_line(char s[], int len) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i <= len)
            s[i++] = ch;
    
    s[i] = '\0';
}