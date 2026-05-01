/*
Jermaine Jalen Dikembe R. Alvarez

TOPIC: Array

PROBLEM: Write a program program that accepts as input 30 integers and stores these 3o
integers into an array. The program should calculate and display the average of all
the integers that are divisible by 4.

INSTRUCTIONS:
1. Write your name at the topmost part of your code.
2. Use modular programming. Remember that each function shall do one task only. So,
input, calculations and display must be in separate functions.
3. All parameters must be variables. Function calls in the parameter section are not allowed.
*/

#include <stdio.h>

#define N 30

void input_num(int array[], int len);
float calc_avg(int array[], int len);
void output_avg(float avg);

int main(void) {
	int num[N];
	float avg;
	
	// input 30 integers
	input_num(num, N);
		
	// calculate average of all integers divisible by 4
	avg = calc_avg(num, N);
	
	// output average of all integers divisible by 4
	output_avg(avg);
				
	return 0;
}

void input_num(int array[], int len) {
	printf("--Input %d number of integers--\n", len);
	for (int i = 0; i < len; i++) {
		printf("Enter integer %d: ", i + 1);
		scanf("%d", &array[i]);
	}
	return;
}

float calc_avg(int array[], int len) {
	int div_len = 0;
	float total = 0.0;
	
	for (int i = 0; i < len; i++) {
		if (array[i] % 4 == 0) {
			total += array[i];
			div_len++;
		}
	}
	
	return total / div_len;
}

void output_avg(float avg) {
	printf("Average: %.2f\n", avg);
	return;
}