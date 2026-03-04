/*
🧠 Project: Bus Fare Calculator
Problem:
A transport company charges fares based on age and distance traveled. The pricing system is as follows:
- Base fare: ₱10 for the first 5 km
- Additional fare: ₱2 per km for each kilometer beyond 5 km
Special rates:
- Children below 5 years old ride for free
- Seniors 60 years and older get 20% discount off the total fare

✅ Requirements:
- Prompt the user to enter:
    - Age
    - Distance traveled in kilometers
- Validate that:
    - Age is a positive integer
    - Distance is at least 1 km
- Compute and display:
    - The base fare
    - The additional fare
    - Total fare before discount
    - Discount (if any)
    - Final fare

📥 Example Input:
Enter age: 65
Enter distance traveled (km): 10

📤 Example Output:
Base fare: ₱10.00
Additional fare: ₱10.00
Total before discount: ₱20.00
Senior discount: ₱4.00
Final fare: ₱16.00

💡 Tips:
- Use int or float as needed.
- You’ll need conditionals (if-else) and maybe the ternary operator.
- Stick to printf formatting to show money nicely, like %.2f.
*/

#include <stdio.h>

int main(void)
{
    int age, distance;
    float base_fare = 10.0f;
    float additional_fare = 2.0f;
    float total_fare = 0.0f;
    float discount_rate = 0.20f;
    float senior_dicount = 0.0f;
    float final_fare = 0.0f;

    printf("Enter age: ");
    scanf("%d", &age);
    printf("Enter distance traveled (km): ");
    scanf("%d", &distance);

    if (age < 0 || distance < 1.0f) {
        printf("Error! Age and distance must be 1 year old/km or above.\n");
        return 1;
    }

    if (age < 5) {
        printf("Passenger is under 5 years old - ride is free.\n");
        printf("Fare: ₱0.00\n");
        return 0;
    }

    if (distance > 5) {
        additional_fare *= distance - 5;
    }

    total_fare = base_fare + additional_fare;

    printf("Base fare: ₱%.2f\n", base_fare);
    printf("Additional fare: ₱%.2f\n", additional_fare);
    
    if (age >= 60) {
        printf("Total before discount: ₱%.2f\n", total_fare);

        senior_dicount = total_fare * discount_rate;
        final_fare = total_fare - senior_dicount;
        printf("Senior discount: ₱%.2f\n", senior_dicount);
        printf("Final fare: ₱%.2f\n", final_fare);
    } else {
        final_fare = total_fare;
        printf("Final fare: ₱%.2f\n", final_fare);
    }

    return 0;
}