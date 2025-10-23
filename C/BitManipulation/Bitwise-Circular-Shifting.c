/*
  Bitwise Circular Shifting
  Perform bitwise circular shifting
  Algorithm:-
  Easiest way is to shift the bits we expect, then make the removed 
  bits go back to the head/tail of the number.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int circular_shift_8bit(unsigned int word, unsigned int shift) {
    if (word > 255) {
        printf("Word should be less than 256\n");
        return 0;
    }
    if (shift > 7) {
        printf("Shift should be less than 8\n");
        return 0;
    }
    return ((word << (shift&7)) | ((word >> ((8-shift) & 7))));
}

void print(unsigned int value) {
    printf("Value:%d\n", value);
    int i;
    for(i = 0; i<8; i++) {
        if (value & (0x80>>i)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
}

int main() {
    printf("Test-Case-1 : Word = 13\n");
    print(13);
    int result = circular_shift_8bit(13,3);
    print(result);
    printf("\n");
    printf("Test-Case-2: Word = 8\n");
    print(8);
    result = circular_shift_8bit(8,2);
    print(result);

    return 0;
}