/*
🧠 Project: Parking Fee Calculator
🚗 Situation:
You are building a billing system for a small parking lot. The customer inputs entry and exit times (in 24-hour format), 
and the program computes the parking fee.

✅ Rules:
- First 2 hours = ₱40
- Each additional hour or part thereof = ₱20 per hour
- Maximum charge = ₱200
- If exit time is earlier than entry time, assume they stayed overnight (crossed midnight)

📥 Input Format:
- Enter entry time (hour and minute): hh mm
- Enter exit time (hour and minute): hh mm
All inputs are integers and in 24-hour format (0–23 for hour, 0–59 for minute).

📤 Output Example:
Sample Input:
Enter entry time (hh mm): 21 30  
Enter exit time (hh mm): 1 15

Sample Output:
Total parking time: 3 hours, 45 minutes  
Parking fee: ₱100.00

🧠 How it's calculated:
1. Convert both times into total minutes since midnight
2. Compute duration in minutes
3. Round up to the next full hour
4. Apply the pricing rules
5. Cap fee at ₱200 if needed
*/

#include <stdio.h>

int main(void)
{
    int entry_hour, entry_minute, exit_hour, exit_minute;
    int entry_total_minutes, exit_total_minutes;
    int duration, full_hour;
    int fee = 0;

    printf("Enter entry time (hh:mm): ");
    scanf("%d %d", &entry_hour, &entry_minute);

    printf("Enter exit time (hh:mm): ");
    scanf("%d %d", &exit_hour, &exit_minute);

    entry_total_minutes = entry_hour * 60 + entry_minute;
    exit_total_minutes = exit_hour * 60 + exit_minute;

    if (exit_total_minutes < entry_total_minutes) {
        exit_total_minutes += 1440;
    }

    duration = exit_total_minutes - entry_total_minutes;
    full_hour = (duration + 59) / 60;    

    if (full_hour <= 2) {
        fee = 4000;
    } else {
        fee = 4000 + (full_hour - 2) * 2000;
    }

    if (fee > 20000) {
        fee = 20000;
    }

    printf("Total parking time: %d hour%c, %d minute%c\n", 
        duration / 60, (duration / 60 == 1) ? '\0' : 's', 
        duration % 60, (duration % 60 == 1) ? '\0' : 's');
    printf("Parking fee: ₱%.2f\n", fee / 100.0);
    

    return 0;
}   