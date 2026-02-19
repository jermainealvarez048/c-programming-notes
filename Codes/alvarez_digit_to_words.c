/*
Write a program that will ask for an integer input (1 - 9999). Your program will convert the inputted integer into its corresponding word format in English. See examples below:

Example 1:

Input number: 2481

Output: two thousand four hundred eighty one

Example 2:

Input number: 616

Output: six hundred sixteen

Example 3:

Input number: 30

Output: thirty

- Make sure to trap your input. Any integer input below 1 or above 9999 is an invalid input. In case of an invalid input, the program will display an error message and will exit the program.

-Submit your .C file.

- Find a way to be able to extract each digit according to its place value.

- VERY IMPORTANT: THE SOLUTION DOES NOT USE 9999 IF-STATEMENTS!

- Be careful on the numbers from 10 - 19.
*/

#include <stdio.h>

int main() {
	int num;
	int thousands, hundreds, tens, ones;
	
	printf("Input number (1 - 9999): ");
	scanf("%d", &num);
	
	if (num < 1 || num > 9999) {
		printf("Error! Enter numbers 1 - 9999 range only.\n");
		return 1;
	}
	
	thousands = num / 1000;
	hundreds = (num % 1000) / 100;
	tens = (num % 100) / 10;
	ones = num % 10;
	
	printf("Output: ");
	// thousands place
	if (thousands == 1) printf("one thousand ");
	else if (thousands == 2) printf("two thousand ");
	else if (thousands == 3) printf("three thousand ");
	else if (thousands == 4) printf("four thousand ");
	else if (thousands == 5) printf("five thousand ");
	else if (thousands == 6) printf("six thousand ");
	else if (thousands == 7) printf("seven thousand ");
	else if (thousands == 8) printf("eight thousand ");
	else if (thousands == 9) printf("nine thousand ");
	
	//hundreds place
	if (hundreds == 1) ("one hundred ");
	else if (hundreds == 2) printf("two hundred ");
	else if (hundreds == 3) printf("three hundred ");
	else if (hundreds == 4) printf("four hundred ");
	else if (hundreds == 5) printf("five hundred ");
	else if (hundreds == 6) printf("six hundred ");
	else if (hundreds == 7) printf("seven hundred ");
	else if (hundreds == 8) printf("eight hundred ");
	else if (hundreds == 9) printf("nine hundred ");
	
	//tens
	if (tens == 1) {
		if (ones == 9) printf("nineteen ");
		else if (ones == 8) printf("eighteen ");
		else if (ones == 7) printf("seventeen ");
		else if (ones == 6) printf("sixteen ");
		else if (ones == 5) printf("fifteen ");
		else if (ones == 4) printf("fourteen ");
		else if (ones == 3) printf("thirteen ");
		else if (ones == 2) printf("twelve ");
		else if (ones == 1) printf("eleven "); 
		else if (ones == 0) printf("ten ");
	} else {
		if (tens == 2) printf("twenty ");
		else if (tens == 3) printf("thirty ");
		else if (tens == 4) printf("forty ");
		else if (tens == 5) printf("fifty ");
		else if (tens == 6) printf("sixty ");
		else if (tens == 7) printf("seventy ");
		else if (tens == 8) printf("eighty ");
		else if (tens == 9) printf("ninety ");
	}

	// ones
	if (tens != 1) {
		if (ones == 1) printf("one ");
		else if (ones == 2) printf("two ");
		else if (ones == 3) printf("three ");
		else if (ones == 4) printf("four ");
		else if (ones == 5) printf("five ");
		else if (ones == 6) printf("six ");
		else if (ones == 7) printf("seven ");
		else if (ones == 8) printf("eight ");
		else if (ones == 9) printf("nine ");
	}
	printf("\n");
	
	return 0;
}