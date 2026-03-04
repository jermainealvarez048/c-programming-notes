/*
Although guess.c works fine, it relies on an external variable. We made
secret_number external so that both choose_new_secret_number and
read_guesses could access it. If we alter choose_new_secret_number
and read_guesses just a little, we should be able to move secret_number
into the main function. We’ll modify choose_new_secret_number so
that it returns the new number, and we’ll rewrite read_guesses so that
secret_number can be passed to it as an argument.

Here’s our new program, with changes in bold:
*/

/* Asks user to guess a hidden number */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

/* prototypes */
void initialize_number_generator(void);
int new_secret_number(void);
void read_guesses(int secret_number);

int main(void) {
    char command;
    int secret_number;
    
    printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    initialize_number_generator();
    do {
        secret_number = new_secret_number();
        printf("A new number has been chosen.\n");
        read_guesses(secret_number);
        printf("Play again? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");
    } while (command == 'y' || command == 'Y');
    
    return 0;
}

/********************************************************** 
 * initialize_number_generator: Initializes the random    *
 *                              number generator using    *
 *                              the time of day.          *
 **********************************************************/
void initialize_number_generator(void)
{
    srand((unsigned) time(NULL));   
}

int new_secret_number(void) {
    return rand() % MAX_NUMBER + 1;
}
/**********************************************************
 * read_guesses: Repeatedly reads user guesses and tells  *
 *               the user whether each guess is too low,  *
 *               too high, or correct. When the guess is  *
 *               correct, prints the total number of      *
 *               guesses and returns.                     *
 **********************************************************/
void read_guesses(int secret_number) {
    int guess, num_guesses = 0;
    for (;;) {
        num_guesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        
        if (guess == secret_number) {
            printf("You won in %d guesses!\n\n", num_guesses);
            return;
        } else if (guess < secret_number)
            printf("Too low; try again.\n");
        else
            printf("Too high; try again.\n");
    }
}