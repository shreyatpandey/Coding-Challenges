#include <stdio.h>
#include <stdlib.h>

int trailing_zeros(unsigned int num) {
    if (num == 0) {
        return 32; // All 32 bits are zeros
    }
    int result_count = 0;
    while (num & 1) {
        result_count++;
        num >>= 1;
    }
    return result_count;
}

int main (int argc, char *argv[]) {
    unsigned int num;
    num = atoi(argv[1]);

    int trailing_zeros_count = trailing_zeros(num);
    printf("Number of trailing zeros: %d\n", trailing_zeros_count);

    return 0;
}