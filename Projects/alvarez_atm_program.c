/*
ATM simulation commands:
1. Deposit
2. Withdraw
3. Balance Inquiry
4. Fast Cash

Note: Program will exit from main menu option.
- Program must trap invalid inputs (no negative values and must not be able to withdraw more than the balance)
- Deposit will add to the balance
- Withdraw will deduct from balance
- Balance Inquiry will show current balance
- Fast cash will show amounts to withdraw: P20, P50, P100, P200, P500, P1000
- Return to main menu if there are invalid inputs
- Balance is always 0.00 at the start of the program
- Will only exit the program when Exit is chosen from the Main Menu
*/

#include <stdio.h>

int main() {
	float balance = 0.00, amount;
	int option;
	char choice;
	
	do {
		printf("\nPLEASE CHOOSE THE TRANSACTION:\n");
		printf("1. DEPOSIT\n2. WITHDRAW\n3. BALANCE INQUIRY\n4. FAST CASH\n5. EXIT\n");
		
		printf("ENTER OPTION: ");
		scanf("%d", &option);
		
		switch (option) {
			case 1: 
				printf("-DEPOSIT AMOUNT: ");
				scanf("%f", &amount);
				
				if (amount < 1) {
					printf("INVALID AMOUNT.\n");
				} else {
					balance += amount;	
					printf("--DEPOSIT SUCCESSFUL!\n");
					printf("--NEW BALANCE: %.2f\n", balance);
				}
				break;
				
			case 2:
				printf("-WITHDRAW AMOUNT: ");
				scanf("%f", &amount);
			
				if (amount < 1) {
					printf("INVALID AMOUNT.\n");
				}
				else if (amount > balance) {
					printf("INSUFFICIENT BALANCE.\n");
				} else {
					balance -= amount;
					printf("--WITHDRAW SUCCESSFUL!\n");
					printf("--NEW BALANCE: %.2f\n", balance);
				}
				break;
				
			case 3: 
				printf("-BALANCE: %.2f\n", balance);
				break;
				
			case 4:
				printf("-SELECT FAST CASH AMOUNT [20] [50] [100] [200] [500] [1000]\n: ");
				scanf("%f", &amount);	
				
				if (amount != 20 && amount != 50 && amount != 100 &&
					amount != 200 && amount != 500 && amount != 1000) {
					printf("INVALID FAST CASH AMOUNT.\n");	
				}	
				else if (amount > balance) {
					printf("INSUFFICIENT BALANCE.\n");
				} else {
					balance -= amount;
					printf("--FAST CASH OF %.2f SUCCESSFUL!\n", amount);
					printf("--NEW BALANCE: %.2f\n", balance);
				}
				break;
			
			case 5:
				printf("\n--THANK YOU FOR BANKING WITH US!--\n");
				return 0;
			
			default: printf("INVALID INPUT.\n"); break;
		}
		
		printf("WOULD YOU LIKE TO DO ANOTHER TRANSACTION (Y/n): ");
		scanf(" %c", &choice);
	} while (choice == 'Y' || choice == 'y');
	
	return 0;
}