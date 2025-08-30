#include <stdio.h>
#include <stdlib.h>

/* Definition of Trailing Zeros */
/* Trailing zeros in a binary number are the consecutive zeros that appear at the end (rightmost side) of the binary representation of the number. */

int trailing_zeros(unsigned int num) {
    if (num == 0) {
        return 32; // All 32 bits are zeros
    }
    int result_count = 0;
    while ((num & 1) == 0) {
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
/*
 For example:
 For binary number 1000 (8 in decimal), it will return 3
 For binary number 1010 (10 in decimal), it will return 1
 For binary number 1011 (11 in decimal), it will return 0
*/