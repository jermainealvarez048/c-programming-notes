/*
Finding the Largest and Smallest Elements in an Array

To illustrate how pointers are passed to functions, let’s look at a function named
max_min that finds the largest and smallest elements in an array. When we call
max_min, we’ll pass it pointers to two variables; max_min will then store its
answers in these variables. max_min has the following prototype:

void max_min(int a[], int n, int *max, int *min);

A call of max_min might have the following appearance:

max_min(b, N, &big, &small);

b is an array of integers; N is the number of elements in b. big and small are
ordinary integer variables. When max_min finds the largest element in b, it stores
the value in big by assigning it to *max. (Since max points to big, an assign
ment to *max will modify the value of big.) max_min stores the smallest ele
ment of b in small by assigning it to *min.
To test max_min, we’ll write a program that reads 10 numbers into an array,
passes the array to max_min, and prints the results:

Enter 10 numbers: 34 82 49 102 7 94 23 11 50 31
Largest: 102
Smallest: 7
*/

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void) {
    int b[N];
    int big, small;

    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++)
        scanf("%d", &b[i]);

    max_min(b, N, &big, &small);
    
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);
}

void max_min(int a[], int n, int *max, int *min) {
    int i;

    *max = *min = a[0];
    for (i = 1; i < n; i++) {
        if (a[i] > *max)
            *max = a[i];
        else if (a[i] < *min)
            *min = a[i];
    }
}