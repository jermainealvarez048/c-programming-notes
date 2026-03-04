/*
Write the following function:
double inner_product(const double *a, const double *b,
                     int n);
a and b both point to arrays of length n. The function should return a[0] * b[0] +
a[1] * b[1] + … + a[n-1] * b[n-1]. Use pointer arithmetic—not subscripting—to
visit array elements.
*/


double inner_product(const double *a, const double *b, int n) {
    const double *p, *q; 
    double sum = 0.0;
    for (p = a, q = b; p < a + n && q < b + n; p++, q++)
        sum += (*p) * (*q);
        
    return sum;
}

//or

double inner_product(const double *a, const double *b, int n) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += (*a++) * (*b++);
    }    
    
    return sum;
}

