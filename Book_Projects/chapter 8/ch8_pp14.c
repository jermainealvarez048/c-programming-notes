/*
Write a program that reverses the words in a sentence:

Enter a sentence: you can cage a swallow can't you?
Reversal of sentence: you can't swallow a cage can you?

Hint: Use a loop to read the characters one by one and store them in a one-dimensional
char array. Have the loop stop at a period, question mark, or exclamation point (the “termi
nating character”), which is saved in a separate char variable. Then use a second loop to
search backward through the array for the beginning of the last word. Print the last word,
then search backward for the next-to-last word. Repeat until the beginning of the array is
reached. Finally, print the terminating character.
*/

#include <stdio.h>

int main(void) {
    char sentence[100];
    char ch, end_char;
    int len = 0;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '.' && ch != '?' && ch != '!') 
        sentence[len++] = ch;
    end_char = ch;

    printf("Reversal of sentence:");
    int i = len - 1;
    while (i >= 0) {
        while (i >= 0 && sentence[i] == ' ')
            i--;
        
        if (i < 0)
            break;
        
        int end = i;
        while (i >= 0 && sentence[i] != ' ')
            i--;
        int start = i + 1;

        printf(" ");
        for (int j = start; j <= end; j++)
            printf("%c", sentence[j]);
    }
    printf("%c\n", end_char);

    return 0;
}