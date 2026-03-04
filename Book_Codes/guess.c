/*
Guessing a Number

To get more experience with external variables, we’ll write a simple game-playing
program. The program generates a random number between 1 and 100, which the
user attempts to guess in as few tries as possible. Here’s what the user will see
when the program is run:

Guess the secret number between 1 and 100.

A new number has been chosen.
Enter guess: 55
Too low; try again.
Enter guess: 65
Too high; try again.
Enter guess: 60
Too high; try again.
Enter guess: 58
You won in 4 guesses!

Play again? (Y/N) y

A new number has been chosen.
Enter guess: 78
Too high; try again.
Enter guess: 34
You won in 2 guesses!

Play again? (Y/N) n

This program will need to carry out several different tasks: initializing the ran
dom number generator, choosing a secret number, and interacting with the user
until the correct number is picked. If we write a separate function to handle each
task, we might end up with the following program.
*/

/* Asks user to gess a hidden number */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int secret_number;

void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int main(void) {
    char command;
    printf("Guess the secret number between 1 and %d\n\n", MAX_NUM);
    initialize_number_generator();
    do {
        choose_new_secret_number();
        printf("A new number has been chosen.\n");
        read_guesses();
        printf("\nTry again? (Y/n) ");
        scanf(" %c", &command);
    } while (command == 'Y' || command == 'y');

    return 0;
}

/**********************************************************
 * initialize_number_generator: Initializes the random    *
 *                              number generator using    *
 *                              the time of day.          *
 **********************************************************/
void initialize_number_generator(void) {
    srand((unsigned) time(NULL));
}


/********************************************************** 
 * choose_new_secret_number: Randomly selects a number    * 
 *                           between 1 and MAX_NUMBER and * 
 *                           stores it in secret_number.  * 
 **********************************************************/
void choose_new_secret_number(void) {
    secret_number = rand() % MAX_NUM + 1;
}

/**********************************************************
 * read_guesses: Repeatedly reads user guesses and tells  *
 *               the user whether each guess is too low,  *
 *               too high, or correct. When the guess is  *
 *               correct, prints the total number of      *
 *               guesses and returns.                     *
 **********************************************************/
void read_guesses(void) {
    int guess, num_guesses = 0;

    for (;;) {
        num_guesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        if (guess == secret_number) {
            printf("You won in %d guess%s!\n", num_guesses, num_guesses == 1 ? "\0" : "es");
            return;
        }
        else if (guess > secret_number)
            printf("Too high; try again.\n");
        else 
            printf("Too low; try again.\n");
    }
}