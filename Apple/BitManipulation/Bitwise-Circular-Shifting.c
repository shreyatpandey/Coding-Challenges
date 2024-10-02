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


unsigned int _8bit_leftrotate(unsigned int word, unsigned int shift) {
    return ((word << (shift&7)) | ((word >> ((8-shift) & 7))));
}

int main() {
    printf("Test-Case-1:%u\n", _8bit_leftrotate(12,3));
    printf("Test-Case-2:%u\n", _8bit_leftrotate(8,2));
}