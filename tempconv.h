#include <stdio.h>
#include <stdlib.h>
#include <errno.h> 
#include <limits.h>

float c2f(int celsius) {
    return ((celsius * 1.8) + 32);
}

float f2c(int fahrenheit) {
    return ((fahrenheit - 32) * 1.8);
}

int parsetemp( const char* input, int* temp) {
    char* endptr;
    long value;
    errno = 0;
    value = strtol(input, &endptr, 10);

    if (errno != 0 || *endptr != '\0') {
        return 0;
    }
    if (value < INT_MIN || value > INT_MAX) {
        return 0;
    }

    *temp = (int)value;
    return 1;
}
