/* Jermaine Jalen Dikembe R. Alvarez */

#include <stdio.h>

#define N 30

void input_arr(int arr[], int size);
void sort_arr(int arr[], int size);
float calc_mean(int arr[], int size);
float calc_median(int arr[], int size);
int calc_mode(int arr[], int mode[], int size);
void output_calc(float mean, float median, int mode[], int mode_count, int arr[], int size);

int main(void) {
	char option;
	
	do {
		int a[N];
	
		// input N positive integers
		input_arr(a, N);
		
		// sort array using bubble sort
		sort_arr(a, N);
		
		// calculate mean (average)
		float mean = calc_mean(a, N);
		
		// calculate median
		float median = calc_median(a, N);
		
		// check mode
		int mode[N];
		int mode_num = calc_mode(a, mode, N); 
		
		// output calculations
		output_calc(mean, median, mode, mode_num, a, N);
		
		printf("Try again (Y/n): ");
		scanf(" %c", &option);
	} while (option == 'Y' || option == 'y');
	
	return 0;
}

void input_arr(int arr[], int size) {
	printf("Input %d integers\n", size);
	int i = 0;
	do {
		printf("Enter integer %d: ", i + 1);
		scanf("%d", &arr[i]);
		if (arr[i] <= 0) {
			printf("Invalid! No nonpositive integers.\n");
			continue;
		} else {
			i++;
		}
	} while (i < size);
}

void sort_arr(int arr[], int size) {
	int i, j, temp;
	for (i = 0; i < size; i++) {
		for (j = size - 1; j > i; j--) {
			if (arr[j] < arr[j-1]) {
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

float calc_mean(int arr[], int size) {
	int i, total = 0;
	for (i = 0; i < size; i++) 
		total += arr[i];
	return (float) total / size;
}

float calc_median(int arr[], int size) {
	if (size % 2 == 0) {
		int floor = size / 2;
		int ceiling = (size / 2) + 1;
		return (arr[floor-1] + arr[ceiling-1]) / 2.0;
	} else {
		return arr[((size+1) / 2.0) - 1];
	}
}

int calc_mode(int arr[], int mode[], int size) {
	int freq[size];
	int i, j, mode_count = 0;
	for (i = 0; i < size; i++) {
		freq[i] = 0;
		for (j = 0; j < size; j++) {
			if (arr[i] == arr[j])
				freq[i]++;
		}
	}
	
	int highest_freq = freq[0];
	for (i = 1; i < size; i++) {
		if (freq[i] > highest_freq)
			highest_freq = freq[i];
	}
	
	if (highest_freq == 1) {
		return 0;
	} else {
		for (i = 0; i < size; i++) {
			if (freq[i] == highest_freq) {
				int seen = 0;
				
				for (j = 0; j < mode_count; j++) {
					if (mode[j] == arr[i]) {
						seen = 1;
						break;
					}
				}
				
				if (!seen)
					mode[mode_count++] = arr[i];
			}
		}
		
		return mode_count;
	}
}

void output_calc(float mean, float median, int mode[], int mode_count, int arr[], int size) {
	printf("\nMean: %.2f\n", mean);
	printf("Median: %.2f\n", median);
	printf("Mode:");
	int i;
	if (mode_count == 0) {
		printf(" (all unique)");
		for (i = 0; i < size; i++)
			printf(" %d", arr[i]);
		printf("\n");
		return;
	} else {
		for (i = 0; i < mode_count; i++)
			printf(" %d", mode[i]);
		printf("\n");
		return;
	}
}