// K&R Exercise 1-9
#include <stdio.h>

#define NUMSPACES 2

int main(void) {
    int c;

    while ((c = getchar()) != EOF)
        if (c == ' ') {
            for (size_t i = 0; i <= NUMSPACES; i++)
            {
                putchar(c);
            }
        }
        else
            putchar(c);
    return 0;
}