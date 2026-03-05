// A simple, real-time clock in the terminal.

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main() {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[9];

    while (1) {
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        strftime(buffer, 80, "%I:%M:%S %p", timeinfo);
        printf("\033[H\033[J");
        printf("---DIGITAL CLOCK---\n");
        printf("--- %s ---\n", buffer);
        printf("-------------------\n");
        fflush(stdout);
        sleep(1);
    }

    return 0;
}
