#include <stdint.h>
#include <stdio.h>

// Function to reverse bits of a 32-bit integer in O(1)
uint32_t reverseBits(uint32_t n) {
    n = ((n & 0x55555555) << 1) | ((n & 0xAAAAAAAA) >> 1);
    n = ((n & 0x33333333) << 2) | ((n & 0xCCCCCCCC) >> 2);
    n = ((n & 0x0F0F0F0F) << 4) | ((n & 0xF0F0F0F0) >> 4);
    n = ((n & 0x00FF00FF) << 8) | ((n & 0xFF00FF00) >> 8);
    n = (n << 16) | (n >> 16);
    return n;
}

int main() {
    uint32_t num;
    printf("Enter a 32-bit integer: ");
    scanf("%u", &num);

    uint32_t reversed = reverseBits(num);
    printf("Reversed bits: %u\n", reversed);

    return 0;
}
