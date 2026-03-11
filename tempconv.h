#ifndef TEMPCONV_H
#define TEMPCONV_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

static inline float c2f(int celsius) {
    return ((celsius * 1.8f) + 32.0f);
}

static inline float f2c(int fahr) {
    /* Fahrenheit to Celsius: (F - 32) * 5/9 */
    return ((fahr - 32) * (5.0f / 9.0f));
}

static inline int parsetemp(const char* input, int* temp) {
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

#endif // TEMPCONV_H
