#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(const int argc, char *argv[]) {
    char input[50];
    printf("Enter a string: ");
    if (scanf("%49s", input) != 1) {
        printf("input error.\n");
        return 1;
    } else {
        printf("%s is %ld characters long.\n", input, strlen(input));
        return 0;
    }
}