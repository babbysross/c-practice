#include <stdio.h>
#include <stdlib.h>

//Todo: Input validation for invalid year entries e.g. w024, 2-20, $(reboot)

int main(int argc, char **argv) {
    int year;                                   //Declare year variable

    if (argc > 2) {                             //Input validation, max 1 argument
        printf("Usage: %s <year>\n, argv[0]");
        return 1;
    } else if (argc < 2) {                      //Ask for input if there's no argument
        printf("What year is it?: \n");
        scanf("%d", &year);
    } else {                                    //Convert passed year argument to int
        year = atoi(argv[1]);
        printf("%d\n", year);
    }

    if (year % 4 == 0 && year % 100 != 0) {     //Check first two leap year criteria
        printf("%d is a leap year!\n", year);
    } else if (year % 400 == 0) {               //Check final leap year criteria
        printf("%d is a leap year!\n", year);
    } else {                                    //Confirm if not a leap year
        printf("%d isn't a leap year.\n", year);
    }
    return 0;
}
