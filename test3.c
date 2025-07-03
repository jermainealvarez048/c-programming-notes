#include <stdio.h>

int main(void)
{
    int age;
    float distance;
    float base_fare = 10.0f;
    float additional_fare = 0.0f;
    float total_fare = 0.0f;
    float discount = 0.0f;
    float final_fare = 0.0f;

    // Input
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Enter distance traveled (km): ");
    scanf("%f", &distance);

    // Input validation
    if (age < 0 || distance < 1.0f) {
        printf("Invalid input.\n");
        return 1;
    }

    // Free ride for children under 5
    if (age < 5) {
        printf("\nPassenger is under 5 years old — ride is free.\n");
        printf("Fare: ₱0.00\n");
        return 0;
    }

    // Fare computation
    if (distance > 5.0f) {
        additional_fare = (distance - 5.0f) * 2.0f;
    }

    total_fare = base_fare + additional_fare;

    // Senior discount
    if (age >= 60) {
        discount = total_fare * 0.20f;
    }

    final_fare = total_fare - discount;

    // Output
    printf("\nBase fare: ₱%.2f\n", base_fare);
    printf("Additional fare: ₱%.2f\n", additional_fare);
    printf("Total before discount: ₱%.2f\n", total_fare);

    if (age >= 60) {
        printf("Senior discount: ₱%.2f\n", discount);
    }

    printf("Final fare: ₱%.2f\n", final_fare);

    return 0;
}
