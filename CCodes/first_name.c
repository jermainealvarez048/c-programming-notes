/* First name input */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool is_capital_letter = false;
    char capital_letters[26] = 
        {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
         'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char first_name[20];;
    char ch;
    int len = 0;

    printf("Enter first name: ");
    while (1) {
        if (len > 20) {
            printf("First name must be 8 - 20 characters long.\n");
            return 1;
        }
        
        scanf("%c", &first_name[len]);
        if (first_name[len] == '\n' && len < 8) {
            printf("First name must be 8 - 20 characters long.\n");
            return 1;
        } 
        if (first_name[len] == '\n' || first_name[len] == ' ')
            break;
        
        len++;
    }

    for (int i = 0; i <= 26; i++) {
        if (first_name[0] == capital_letters[i])
            is_capital_letter = true;
    }
    if (!is_capital_letter) {
        printf("Invalid! First letter must be in capital.\n");
        return 1;
    }

    printf("hello, ");
    for (int i = 0; i < len; i++) 
        printf("%c", first_name[i]);
    printf("\n");

    return 0;
}