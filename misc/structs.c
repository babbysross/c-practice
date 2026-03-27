#include <stdio.h>

typedef struct {
    char *name;
    int age;
} Stats; 

Stats boys[] =  {
    {"Freddie", 20},
    {"Jonas", 15},
    {"Billy", 18}
};

int main() {
    printf("%s is %d years old.\n", boys[0].name,boys[0].age);
    return 0;
}