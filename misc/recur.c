#include <stdio.h>

void count_vanilla(int start, int end) {
    if (start > end) return;
    printf("%d\n", start);
    count_vanilla((start+1),end);
}

void count(int start, int end) {
iterate:
    if (start > end) return;
    printf("%d %p\n", start, &start);
    start++;
    goto iterate;
}

int main(void) {
    count(0,9);
    return 0;
}