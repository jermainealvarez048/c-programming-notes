/*
--WATER BILLING SYSTEM--

🧠 Scenario:
You work for a local water district. They asked you to create a simple water billing system for residential
customers based on their monthly water usage (in cubic meters). The customer gives their previous and current
meter readings. You will compute the total consumption and the corresponding bill.

📏 Billing Rules:
- First 10 cubic meters: ₱200 flat (minimum charge)
- Next 20 cubic meters (from 11 to 30): ₱25 per cubic meter
- Beyond 30 cubic meters: ₱30 per cubic meter

💡 Input Requirements:
- Previous meter reading (int)
- Current meter reading (int)

🧮 What to compute:
- Water consumed (current - previous)
- Bill based on the rules
- Display water consumed and final bill (use .2f formatting)

Example 1:
Input previous reading: 1200  
Input current reading: 1225

Output:  
Water used: 25 cubic meters  
Total bill: ₱625.00

Example 2:
Input previous reading: 150  
Input current reading: 155

Output:  
Water used: 5 cubic meters  
Total bill: ₱200.00
*/

#include <stdio.h>

int main(void)
{
    int previous_meter_reading;
    int current_meter_reading;
    int water_consumed;
    long bill;

    printf("Input previous reading: ");
    scanf("%d", &previous_meter_reading);

    printf("Input current reading: ");
    scanf("%d", &current_meter_reading);

    water_consumed = current_meter_reading - previous_meter_reading;

    if (water_consumed <= 10) {
        bill = 20000;
    }
    else if (water_consumed <= 30) {
        bill = 20000 + (water_consumed*25) * 100;
    } else {
        bill = 20000 + (water_consumed*30) * 100;
    }

    printf("Water used: %d cubic meters\n", current_meter_reading - previous_meter_reading);
    printf("Total bill: ₱%.2f\n", bill / 100.0);

    return 0;
}