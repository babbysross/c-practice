// K&R Exercise 1-8

#include <stdio.h>

#define IN 1
#define OUT 0

int main(void) {
    int c, nl, nw, nc, nb, state;

    state = OUT;
    nl = nb = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ')
            ++nb;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d %d\n", nl, nb, nw, nc);
    return 0;
}