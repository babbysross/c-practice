// A calculator to determine if a given year is a leap year or not.

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int isleapyear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int parseyear(const char* input, int* year) {
    char* endptr;
    long value;
    errno = 0;
    value = strtol(input, &endptr, 10);

    if (errno != 0 || *endptr != '\0') {
        return 0;
    }
    if (value <1 || value > INT_MAX) {
        return 0;
    }

    *year = (int)value;
    return 1;
}

int main(int argc, char **argv) {
    int year;                                   //Declare year variable
    char input[50];

    if (argc > 2) {                             //Input validation, max 1 argument
        printf("Usage: %s <year>\n", argv[0]);
        return 1;
    }

    if (argc == 2) {
        if (!parseyear(argv[1], &year)) {
            printf("Invalid year entered.\n");
            return 1;
        }
    } else {
            printf("Enter a year: ");

            if (scanf("%49s", input) != 1) {
                printf("\nInput error.\n");
                return 1;
            }

            if (!parseyear(input, &year)) {
                printf("\nInvalid year entered.\n");
                return 1;
            }
        }


    if (isleapyear(year)) {     //Check input against leap year criteria
        printf("%d is a leap year!\n", year);
    } else {                                    //Confirm if not a leap year
        printf("%d isn't a leap year.\n", year);
    }
    return 0;
}
