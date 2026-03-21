// K&R Exercise 1-14

#include <stdio.h>

#define ARRSIZE 200

int main(void) {
    int c;
    int char_freq[ARRSIZE];

    for (int i = 0; i < ARRSIZE; ++i)
        char_freq[i] = 0;

    while ((c = getchar()) != EOF) {
        ++char_freq[c];
    }

    printf("Character Count Histogram:\nX    1 2 3 4 5 6 7 8 9 10+ \n--------------------------\n");
    for (int i = 1; i < ARRSIZE; ++i) {
        if (char_freq[i] > 0) {
            if (i == 32)
            {
                printf("SPC | ");
                for (int j = 0; j < char_freq[i]; ++j)
                    printf("█ ");
            }
            else if (i == 10)
            {
                printf(" \\n | ");
                for (int j = 0; j < char_freq[i]; ++j)
                    printf("█ ");
            }
            else if (i == 9)
            {
                printf("\\t| ");
                for (int j = 0; j < char_freq[i]; ++j)
                    printf("█ ");
            }
            else {
                printf(" %2c | ", i);
                for (int j = 0; j < char_freq[i]; ++j)
                    printf("█ ");
            }
            putchar('\n');
        }
    }
    
    return 0;
}