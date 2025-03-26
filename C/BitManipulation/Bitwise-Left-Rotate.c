#include <stdio.h>
#include <stdint.h>

uint32_t leftRotate(uint32_t n, unsigned int rotations) {
    // Ensure rotations are within the bit range (32 for uint32_t)
    rotations %= 32;

    if (rotations == 0) {
        return n; // No rotation needed
    }

    return (n << rotations) | (n >> (32 - rotations));
}

int main(int argc, char *argv[]) {
    uint32_t n = atoi(argv[1]);
    unsigned int rotations = atoi(argv[2]);
    printf("Value Before Left Rotate : %x\n", n);
    n = leftRotate(n, rotations);
    printf("Value After Left Rotate : %x\n", n);

    return 0;
}