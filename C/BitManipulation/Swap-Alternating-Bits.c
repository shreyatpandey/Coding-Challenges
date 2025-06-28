#include <stdio.h>

unsigned int swap_alternating_bits(unsigned int n) {
    // Mask for odd bits: 0xAAAAAAAA (binary: 101010...10)
    unsigned int odd_bits = n & 0xAAAAAAAA;

    // Mask for even bits: 0x55555555 (binary: 010101...01)
    unsigned int even_bits = n & 0x55555555;

    // Right shift odd bits and left shift even bits
    odd_bits >>= 1;
    even_bits <<= 1;

    // Combine the shifted bits
    return (odd_bits | even_bits);
}

int main() {
    unsigned int n;

    printf("Enter a number: ");
    scanf("%u", &n);

    unsigned int result = swap_alternating_bits(n);

    printf("Number after swapping alternating bits: %u\n", result);

    return 0;
}