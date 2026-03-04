/*
Section 8.2 had a program fragment in which two nested for loops initialized the array
ident for use as an identity matrix. Rewrite this code, using a single pointer to step
through the array one element at a time. Hint: Since we won’t be using row and col index
variables, it won’t be easy to tell where to store 1. Instead, we can use the fact that the first
element of the array should be 1, the next N elements should be 0, the next element should
be 1, and so forth. Use a variable to keep track of how many consecutive 0s have been
stored; when the count reaches N, it’s time to store 1.
*/

#include <stdio.h>

#define N 10

int main(void) {
    double ident[N][N], *p;
    int zero_count = 0;

    for (p =  ident[0]; p < ident[0] + N * N; p++) {
        if (zero_count == 0) {
            *p = 1.0;
            zero_count = N;
        } else {
            *p = 0.0;
            zero_count--;
        }
    }

    int count = 1;
    for (p = ident[0]; p < ident[0] + N * N; p++, count++) {
        printf("%.1f ", *p);
        if (count % N == 0)
            printf("\n");
    }

    return 0;
}

/*
or
#define N 10

double ident[N][N], *p;
int num_zeros = N;

for (p = &ident[0][0]; p <= &ident[N-1][N-1]; p++)
    if (num_zeros == N) {
        *p = 1.0;
        num_zeros = 0;
    } else {
        *p = 0.0;
        num_zeros++;
}
*/