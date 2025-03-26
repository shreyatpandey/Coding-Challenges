#include <stdio.h>
#include <stdlib.h>

uint32_t right_rotate(uint32_t n, int k)
{
    /* Make sure k within 32 bit range */
    k %= 32;
    if (k == 0 || k == 32) {
        return n;
    }
    return (n >> k) | (n << (32 - k));
}

int main (int argc, char *argv[]) {
    uint32_t n = atoi(argv[1]);
    unsigned int k = atoi(argv[2]);
    printf("Value Before Right Rotate : %x\n", n);
    n = right_rotate(n, k);
    printf("Value After Right Rotate : %x\n", n);
    return 0;
}