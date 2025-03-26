/* Count the numbr of bits in an integer */
#include <stdio.h>
#include <stdlib.h>

unsigned int no_of_bits(unsigned int x) {
    unsigned int count = 0;
    while (x) {
        count += 1;
        x = x >> 1;
    }
    return count;
}
int main (int argc, char *argv[]) {
    unsigned int x = atoi(argv[1]);
    printf("Number of bits in %u: %u\n", x, no_of_bits(x));
    return 0;
}