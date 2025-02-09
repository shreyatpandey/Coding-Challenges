/*
 Remove the endiannes in the system
*/
#include <stdio.h>
#include <stdint.h>

int main() {
    unsigned int num = 0x1234;
    unsigned char byteArray[2]; // Since unsigned int is typically 4 bytes, but you want it in a byte array, and the value given is 2 bytes, we use 2 here.

    // Method 1: Using bitwise operations (more portable)
    byteArray[0] = (num >> 8) & 0xFF; // Extract the most significant byte
    byteArray[1] = num & 0xFF;        // Extract the least significant byte

    // Method 2: Using memcpy (potentially faster, but less portable for endianness)
    // #include <string.h>  // Include for memcpy
    // memcpy(byteArray, &num, sizeof(byteArray)); // Potentially issues with endianness.

    printf("Hexadecimal representation of num: 0x%X\n", num);

    printf("Byte array: ");
    for (int i = 0; i < sizeof(byteArray); i++) {
        printf("0x%02X ", byteArray[i]); // Print each byte in hex format
    }
    printf("\n");


    //Illustrating the values (important for understanding endianness)
    printf("byteArray[0]: 0x%02X\n", byteArray[0]);
    printf("byteArray[1]: 0x%02X\n", byteArray[1]);

    //Reconstructing the number from the byte array (Important for verifying endianness)
    unsigned int reconstructedNum;
    reconstructedNum = (byteArray[0] << 8) | byteArray[1]; //For Big Endian
    //reconstructedNum = (byteArray[1] << 8) | byteArray[0]; //For Little Endian

    printf("Reconstructed num: 0x%X\n", reconstructedNum);
    return 0;
}