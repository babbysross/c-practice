#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

float f2c(int fahr) {
    return ((fahr - 32) * 5 / 9);
}

int parsetemp( const char* input, int* temp) {
    char* endptr;
    long value;
    errno = 0;
    value = strtol(input, &endptr, 10);

    if (errno != 0 || *endptr != '\0') {
        return 0;
    }
    if (value < INT_MIN || value > INT_MAX) {
        return 0;
    }

    *temp = (int)value;
    return 1;
}

int main(int argc, char **argv) {
    int fahr;                                   //Declare year variable
    char input[50];

    if (argc > 2) {                             //Input validation, max 1 argument
        printf("Usage: %s <degrees (C)>\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        if (!parsetemp(argv[1], &fahr)) {
            printf("Invalid temperature entered.\n");
            return 1;
        }
    } else {
            printf("Enter a temperature in Celsius: ");

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