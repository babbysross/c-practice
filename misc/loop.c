#include <stdio.h>

int main(void) {
    int a[] = {1, 5, 8, 4, 0};
    int i;
    for (i = 0; a[i] < (sizeof(a)-1); ++i) printf("%d\n", a[i]);
    do {
        printf("%d\n", i--);
    } while (i);
}