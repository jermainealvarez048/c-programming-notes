#include <stdio.h>
#include <string.h>

#define LIST_SIGN "☐"
#define CHECK_SIGN "☐"

#define CHECK_SIGN "☑"

int main(void) {
    printf("--TO-DO List--\n");
    printf("%s Finsih Laundry\n", CHECK_SIGN);
    printf("%s Study Math\n", LIST_SIGN);
    printf("%s Go to Grocery\n", LIST_SIGN);
    printf("%s Drink 8 Glasses of Water\n", CHECK_SIGN);    

    printf("\n%d\n", (int) strlen(LIST_SIGN));
    printf("%d\n", (int) strlen(CHECK_SIGN));

    return 0;
}