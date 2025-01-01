#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <assert.h>

// Structure to represent the packed 4 bytes
typedef uint32_t packed_bytes;

// Function to pack 4 signed bytes into a 32-bit unsigned integer
packed_bytes pack_bytes(int8_t b0, int8_t b1, int8_t b2, int8_t b3) {
    packed_bytes result = 0;

    result |= (uint32_t)(b0 & 0xFF);       // Byte 0
    result |= (uint32_t)(b1 & 0xFF) << 8;   // Byte 1
    result |= (uint32_t)(b2 & 0xFF) << 16;  // Byte 2
    result |= (uint32_t)(b3 & 0xFF) << 24;  // Byte 3

    return result;
}

// Function to extract a signed byte from the packed word
int8_t extract_byte(packed_bytes packed, int byte_num) {
    if (byte_num < 0 || byte_num > 3) {
        fprintf(stderr, "Error: Invalid byte number. Must be between 0 and 3.\n");
        return 0; // Or handle the error in another way
    }

    uint32_t mask = 0xFF << (byte_num * 8);
    uint32_t extracted = (packed & mask) >> (byte_num * 8);

    // Sign extend the extracted byte
    return (int8_t)extracted;
}

// Function to print the packed bytes in hexadecimal format
void print_packed_bytes(packed_bytes packed) {
    printf("Packed Bytes (Hex): 0x%08X\n", packed);
}

// Test function
void test_packing() {
    int8_t b0 = -1;    // 0xFF
    int8_t b1 = 127;   // 0x7F
    int8_t b2 = -128;  // 0x80
    int8_t b3 = 0;     // 0x00

    packed_bytes packed = pack_bytes(b0, b1, b2, b3);
    print_packed_bytes(packed); // Output: 0x00807FFF

    assert(extract_byte(packed, 0) == b0);
    assert(extract_byte(packed, 1) == b1);
    assert(extract_byte(packed, 2) == b2);
    assert(extract_byte(packed, 3) == b3);

    printf("All test cases passed!\n");
}

int main() {
    test_packing();

    // Example usage
    packed_bytes my_packed = pack_bytes(10, 20, -30, 40);
    print_packed_bytes(my_packed);

    int8_t extracted_byte = extract_byte(my_packed, 2);
    printf("Extracted Byte 2: %d\n", extracted_byte);

    return 0;
}