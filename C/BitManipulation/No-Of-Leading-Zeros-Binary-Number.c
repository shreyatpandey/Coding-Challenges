#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* I assume it's 32-bit number */
int countLeadingZeros(uint32_t n) {
    if (n == 0) {
        return 32; // All 32 bits are zeros
    }

    int count = 0;
    uint32_t mask = 0x80000000; // Most significant bit set

    while ((n & mask) == 0) {
        count++;
        mask >>= 1;
    }

    return count;
}

int main(int argc, char *argv[]) {
    uint32_t num;
    num = atoi(argv[1]);

    int leadingZeros = countLeadingZeros(num);
    printf("Number of leading zeros: %d\n", leadingZeros);

    return 0;
}
/*
 For example:
 For binary number 00001000 (8 in decimal), it will return 28 (32 - 4 bits)
 For binary number 01000000 (64 in decimal), it will return 25
 For binary number 10000000 (128 in decimal), it will return 24
*/