#include <stdio.h>
#include <limits.h>
#include "tempconv.h"

int main(int argc, char **argv) {
    int celsius;                                   //Declare year variable
    char input[50];

    if (argc > 2) {                             //Input validation, max 1 argument
        printf("Usage: %s <degrees (C)>\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        if (!parsetemp(argv[1], &celsius)) {
            printf("Invalid temperature entered.\n");
            return 1;
        }
    } else {
            printf("Enter a temperature in Celsius: ");

            if (scanf("%49s", input) != 1) {
                printf("\nInput error.\n");
                return 1;
            }

            if (!parsetemp(input, &celsius)) {
                printf("\nInvalid temperature entered.\n");
                return 1;
            }
        }

        printf("%d°C is equal to %5.1f°F\n", celsius, c2f(celsius));

    return 0;
}
