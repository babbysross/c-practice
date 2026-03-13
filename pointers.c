#include <stdio.h>

/*  Initialise a *pointer like any other variable, and assign it 
    to the address of another variable (&variable returns its address)*/

int main() {
    int number = 42;
    int *pointer = &number;
    printf("The value of number is %d,\n\
The value at number's address is %d,\n\
The address of number is %p.\n", number, *pointer, &number);
    *pointer++;
    printf("See: %d, %d\n", *pointer, *(&number));
/* Printing a pointer variable will output the value stored at the
address it's pointing to. Instead of declaring a pointer, you can also
'dereference' a memory address to get the stored value. (e.g. *(&addr))*/
/* Doing pointer arithmetic changes the targeted memory address, not 
the stored value.*/
    int var = 12;
    int *pt = NULL;
    pt = &var;
    printf("%p, %d, %p\n", pt, *pt, &(*pt));

    /* THe variable name of an array is a pointer to the first value,
    so printing 'princes' would output the address where 5 is stored,
    and printing '*prices' would return the value 5*/
    int prices[3] = { 5, 4, 3 };
    printf("%u\n", *prices); /* 5 */
    printf("%u\n", *(prices + 1)); /* 4 */
    printf("%u\n", *(prices + 2)); /* 3 */
    return 0;
}