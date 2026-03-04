/* Programming Project 1

Write a program that finds the “smallest” and “largest” in a series of words. After the user
enters the words, the program will determine which words would come first and last if the
words were listed in dictionary order. The program must stop accepting input when the user
enters a four-letter word. Assume that no word is more than 20 letters long. An interactive
session with the program might look like this:
Enter word: dog
Enter word: zebra
Enter word: rabbit
Enter word: catfish
Enter word: walrus
Enter word: cat
Enter word: fish
Smallest word: cat
Largest word: zebra
Hint: Use two strings named smallest_word and largest_word to keep track of the
“smallest” and “largest” words entered so far. Each time the user enters a new word, use
strcmp to compare it with smallest_word; if the new word is “smaller,” use strcpy
to save it in smallest_word. Do a similar comparison with largest_word. Use
strlen to determine when the user has entered a four-letter word.
*/

#include <stdio.h>
#include <string.h>

#define STR_LEN 20

void read_line(char str[], int n);

int main(void) {
    char current_word[STR_LEN+1], smallest_word[STR_LEN+1], largest_word[STR_LEN+1];

    read_line(current_word, STR_LEN);
        
    strcpy(smallest_word, current_word);
    strcpy(largest_word, smallest_word);

    while (1) {
        read_line(current_word, STR_LEN);

        if (strlen(current_word) == 4)
            break;
        
        if (strcmp(current_word, smallest_word) < 0)
            strcpy(smallest_word, current_word);
        if (strcmp(current_word, largest_word) > 0)
            strcpy(largest_word, current_word);
    }

    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}

void read_line(char str[], int n) {
    int ch, i = 0;

    printf("Enter word: ");
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
}