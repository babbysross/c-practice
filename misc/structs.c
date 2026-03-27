#include <stdio.h>

typedef struct {
    char name;
    int age;
} boys[10] =  {
    "Freddie", 20,
    "Jonas", 15,
    "Billy", 18
};

int main() {
    printf("%s is %d years old.", boys[0],boys[1]);
    return 0;
}