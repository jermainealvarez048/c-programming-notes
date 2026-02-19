#include <stdio.h>
#include <float.h>
#include <math.h>

int main(void) {
    printf("Checking IEEE 754 compliance...\n\n");
    
    // Check sizes
    printf("Size checks:\n");
    printf("Size of float: %zu bytes\n", sizeof(float));
    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of long double: %zu bytes\n\n", sizeof(long double));
    
    // Check special values
    printf("Special value checks:\n");
    
    // Check for infinity
    double inf = 1.0 / 0.0;  // Should produce infinity in IEEE 754
    printf("1.0 / 0.0 = %f\n", inf);
    printf("Is infinity: %d\n", isinf(inf));
    
    // Check for NaN
    double nan_val = 0.0 / 0.0;  // Should produce NaN in IEEE 754
    printf("0.0 / 0.0 = %f\n", nan_val);
    printf("Is NaN: %d\n\n", isnan(nan_val));
    
    // Check for denormalized numbers
    printf("Denormalized numbers check:\n");
    printf("Minimum positive normalized float: %e\n", FLT_MIN);
    printf("Minimum positive normalized double: %e\n\n", DBL_MIN);
    
    // Check for proper rounding
    printf("Rounding check:\n");
    double a = 0.1 + 0.2;
    double b = 0.3;
    printf("0.1 + 0.2 = %.17f\n", a);
    printf("0.3     = %.17f\n", b);
    printf("Difference = %.17f\n", a - b);
    
    printf("\nConclusion: ");
    if (sizeof(float) == 4 && sizeof(double) == 8 && isinf(inf) && isnan(nan_val)) {
        printf("Your system LIKELY follows IEEE 754 standard.\n");
        printf("Note: This is not a comprehensive test but covers basic requirements.\n");
    } else {
        printf("Your system might NOT follow IEEE 754 standard or has non-standard settings.\n");
    }
    
    return 0;
}