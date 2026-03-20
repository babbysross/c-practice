#include <stdio.h>

void cls(void)
{
    printf("\e[2J\e[H");
    fflush(stdout);
}

int main()
{
    printf("Prepare to clear the screen!");
    //getchar();
    cls();

    return 0;
}