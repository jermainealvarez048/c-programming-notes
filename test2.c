#include <stdio.h>

#define BEGIN {
#define END }
#define LOOP for (;;)

int main(void) 
BEGIN
    #ifdef DEBUG
        printf("Debug Mode\n");
    #endif

    printf("Hello World\n");

    int i = 0;
    LOOP 
    BEGIN
        printf("%d ", i);
        if (i == 10)
            break;
        i++;
    END
    printf("\n");

    return 0;
END