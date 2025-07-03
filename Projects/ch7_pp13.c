/*
Write a program that calculates the average word length for a sentence:

Enter a sentence: It was deja vu all over again.
Average word length: 3.4

For simplicity, your program should consider a punctuation mark to be part of the word to
which it is attached. Display the average word length to one decimal place.
*/

#include <stdio.h>

int main(void)
{
    char ch;
    char word = 0;
    char letter = 0;
    char in_word = 0;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n') {
        if (ch != ' ') {
            letter++;
            if (!in_word) {
                word++;
                in_word = 1;
            }
        } else {
            in_word = 0;
        }
    }

    if (word == 0) {
        printf("Average word length: 0.0\n");
    } else {
        printf("Average word length: %.1f\n", (double) letter / word);
    }
    return 0;
}