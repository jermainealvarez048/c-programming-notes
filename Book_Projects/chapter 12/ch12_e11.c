/*
Modify the find_largest function so that it uses pointer arithmetic—not subscript
ing—to visit array elements.
*/

int find_largest(int arr[], int n) {
    int *max, *p;
    max = arr;
    for (p = arr + 1; p < arr + n; p++) 
        if (*p > *max)
            max = p;
    return *max;
}


