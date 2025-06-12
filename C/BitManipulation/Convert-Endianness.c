#include <stdio.h>
#include <stdint.h>

// Function to swap the endianness of a 32-bit integer
uint32_t swap_endianness(uint32_t num) {
    return ((num >> 24) & 0x000000FF) | // Move byte 3 to byte 0
           ((num >> 8) & 0x0000FF00) |  // Move byte 2 to byte 1
           ((num << 8) & 0x00FF0000) |  // Move byte 1 to byte 2
           ((num << 24) & 0xFF000000);  // Move byte 0 to byte 3
}

int main() {
    uint32_t num;

    printf("Enter a 32-bit integer in hexadecimal (e.g., 0x12345678): ");
    scanf("%x", &num);

    printf("Original number: 0x%08X\n", num);

    uint32_t swapped = swap_endianness(num);
    printf("Number after swapping endianness: 0x%08X\n", swapped);

    return 0;
}
