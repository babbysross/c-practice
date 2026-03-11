#include <stdio.h>

int main(void) {
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      // lower limit of temperature scale
    upper = 300;    // upper limit
    step = 20;      // step size

    fahr = lower;
    printf("Fahrenheit\tCelsius\n");
    while (fahr <= upper) {
        celsius = (5 * (fahr - 32)) / 9;
        printf("%10d\t%7d\n", fahr, celsius);
        fahr += step;
    }
}