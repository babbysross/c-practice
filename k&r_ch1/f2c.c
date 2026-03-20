#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "tempconv.h"

int main(int argc, char **argv) {
    int fahr;                                   //Declare temperature variable
    char input[50];

    if (argc > 2) {                             //Input validation, max 1 argument
        printf("Usage: %s <degrees (F)>\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        if (!parsetemp(argv[1], &fahr)) {
            printf("Invalid temperature entered.\n");
            return 1;
        }
    } else {
            printf("Enter a temperature in Fahrenheit: ");

            if (scanf("%49s", input) != 1) {
                printf("\nInput error.\n");
                return 1;
            }

            if (!parsetemp(input, &fahr)) {
                printf("\nInvalid temperature entered.\n");
                return 1;
            }
        }

        printf("%d°F is equal to %5.1f°C\n", fahr, f2c(fahr));
    
    return 0;
}