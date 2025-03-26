/* Copy set bits from one integer to another within the range */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int copy_set_bits(unsigned int x, unsigned int y, int l, int r) {
    if (l < 1 || r > 32) {
        printf("Invalid range\n");
        return x;
    }
    for (int i = l; i <= r; i++) {
        int mask = 1 << (i - 1);
        if (y & mask) { /* check if the bit is set or not */
            x = x | mask; /* upate x with the corresponding set bit */
        }
    }
    return x;
}

int main () {
    unsigned int x = 10, y = 13, l = 2, r = 3;
    printf("Result: %u\n", copy_set_bits(x, y, l, r));
    return 0;
}