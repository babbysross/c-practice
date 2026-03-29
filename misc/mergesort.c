#include <stdio.h>

/* TO-DO
. Finish implementing the merge sort algorithm
. Implement odd-sized array handling
*/

#define swap(a, b)   \
do {                 \
    int temp = a;    \
    a = b;           \
    b = temp;        \
} while(0)


int *msort(int in[], size_t size) {
    if ((size % 2) != 0)                    //ignores last value if array uneven 
        --size;                             
    for (int i = 0; i < size; i += 2 ) {    //break array up into pairs
        if (in[i+1] <= in[i]) {             //sort pairs if needed
            swap(in[i+1],in[i]);
        }
    }
    //compare a&c, b&c, b&d, ??????
    return in;
} 
// 1 4 3 6
int main(void) {
    int inarray[] = {90, 50, 14, 73, 25, 96, 18, 16, 43, 29, 99};
    size_t arrsize = (sizeof(inarray) / sizeof(*inarray));
    puts("--RAW ARRAY--");
    for (int i = 0; i < arrsize; ++i) {
        printf("%1.2d:\t%d\n", (i + 1), inarray[i]);
    }
    puts("\n--SORTED ARRAY--");
    msort(inarray, arrsize); 
    for (int i = 0; i < arrsize; ++i) {
        printf("%1.2d:\t%d\n", (i + 1), inarray[i]);
    }
    return 0;
}
