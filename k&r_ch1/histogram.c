// K&R Exercise 1-8

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 100

int main(void) {
    int c, state, len;
    int length_freq[MAXLEN];

    for (int i = 0; i <= MAXLEN; ++i)
        length_freq[i] = 0;    

    state = OUT;
    len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                if (len > MAXLEN)
                    ++length_freq[MAXLEN]; //overflow handling
                else
                    ++length_freq[len];
                len = 0; //reset length for next word
            }
            state = OUT;
        } else {
            state = IN;
            ++len;
        }
    }
    
    if (state == IN) { // Handle last word if input doesn't end with whitespace
        if (len > MAXLEN)
            ++length_freq[MAXLEN];
        else
            ++length_freq[len];
    }

    printf("Word Length Histogram:\nX    1 2 3 4 5 6 7 8 9 10+ \n--------------------------\n");
    for (int i = 1; i <= MAXLEN; ++i) {
        if (length_freq[i] > 0) {
            printf("%2d | ", i);
            for (int j = 0; j < length_freq[i]; ++j)
                printf("█ ");
            putchar('\n');
        }
    }
    if (length_freq[MAXLEN] > 0) {
        printf("%2d+ | ", MAXLEN);
        for (int j = 0; j < length_freq[MAXLEN]; ++j)
            putchar('*');
        putchar('\n');
    }
return 0;
}