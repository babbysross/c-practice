#include <stdio.h>

int sum(int a, int b) {
    return a+b;
}

int main(void) {
    printf("Hello, World! %d\n", sum(4, 9));
    return 0;
}