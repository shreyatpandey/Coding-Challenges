#include <stdio.h>
#include <stdlib.h>

int position_of_only_set_bit(unsigned int num) {
    /* Check if the number has more than one set bit */
    if ((num & (num-1)) != 0 || num == 0) {
        return -1;
    }
    int position = 0;
    while (num) {
        if (num & 1) {
            return position;
        }
        position++;
        num >>= 1;
    }
    return position;
}

int main(int argc, char *argv[]) {
    unsigned int num = atoi(argv[1]);
    printf("Position of the only set bit: %d\n", position_of_only_set_bit(num));
    return 0;
}