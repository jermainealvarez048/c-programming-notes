/*
Checking Planet Names

Our next program, planet.c, illustrates how to access command-line argu
ments. The program is designed to check a series of strings to see which ones are
names of planets. When the program is run, the user will put the strings to be tested
on the command line:

planet Jupiter venus Earth fred

The program will indicate whether or not each string is a planet name; if it is, the
program will also display the planet’s number (with planet 1 being the one closest
to the Sun):
Jupiter is planet 5
venus is not a planet
Earth is planet 3
fred is not a planet
Notice that the program doesn’t recognize a string as a planet name unless its first
letter is upper-case and its remaining letters are lower-case.
*/

/* Checks planet names */
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[]) {
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
  int i, j;
  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++)
      if (strcmp(argv[i], planets[j]) == 0) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }
  return 0;
}