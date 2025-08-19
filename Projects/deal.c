/*
Dealing a Hand of Cards

Our next program illustrates both two-dimensional arrays and constant arrays. The
program deals a random hand from a standard deck of playing cards. (In case you
haven’t had time to play games recently, each card in a standard deck has a suit—
clubs, diamonds, hearts, or spades—and a rank—two, three, four, five, six, seven,
eight, nine, ten, jack, queen, king, or ace.) We’ll have the user specify how many
cards should be in the hand:

Enter number of cards in hand: 5
Your hand: 7c 2s 5d as 2h

It’s not immediately obvious how we’d write such a program. How do we pick
cards randomly from the deck? And how do we avoid picking the same card twice?
Let’s tackle these problems separately.

To pick cards randomly, we’ll use several C library functions. The time func
tion (from <time.h>) returns the current time, encoded in a single number. The
srand function (from <stdlib.h>) initializes C’s random number generator.
Passing the return value of time to srand prevents the program from dealing the
same cards every time we run it. The rand function (also from <stdlib.h>)
produces an apparently random number each time it’s called. By using the % oper
ator, we can scale the return value from rand so that it falls between 0 and 3 (for
suits) or between 0 and 12 (for ranks).

To avoid picking the same card twice, we’ll need to keep track of which cards
have already been chosen. For that purpose, we’ll use an array named in_hand
that has four rows (one for each suit) and 13 columns (one for each rank). In other
words, each element in the array corresponds to one of the 52 cards in the deck. All
elements of the array will be false to start with. Each time we pick a card at ran
dom, we’ll check whether the element of in_hand corresponding to that card is
true or false. If it’s true, we’ll have to pick another card. If it’s false, we’ll store
true in that card’s array element to remind us later that this card has already been
picked.

Once we’ve verified that a card is “new”—not already selected—we’ll need to
translate its numerical rank and suit into characters and then display the card. To
translate the rank and suit to character form, we’ll set up two arrays of charac
ters—one for the rank and one for the suit—and then use the numbers to subscript
the arrays. These arrays won’t change during program execution, so we may as
well declare them to be const.
*/

/* Deals a random hand of cards */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) {
   bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
   int num_cards, rank, suit;
   const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
   const char suit_code[] = {'c', 'd', 'h', 's'};

   printf("Enter number of cards in hand: ");
   scanf("%d", &num_cards);

   while (num_cards > 0) {
      rank = rand() % NUM_RANKS;
      suit = rand() % NUM_SUITS;

      if (!in_hand[suit][rank]) {
         in_hand[suit][rank] = true;
         num_cards--;
         printf("%c%c ", rank_code[rank], suit_code[suit]);
      }
   }
   printf("\n");

   return 0;
}