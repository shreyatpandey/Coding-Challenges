
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MASK_8_BIT 0x80

/**
 * Function to swap bits at two given positions in an integer.
 * 
    int bitAtP = (n & (1 << p)) >> p;
    int bitAtQ = (n & (1 << q)) >> q;
    if (bitAtP ^ bitAtQ)
 * @param p The position of the first bit to swap (0-based index).
 * @param q The position of the second bit to swap (0-based index).
 * @return The integer after swapping the bits at positions `p` and `q`.
 */
int swap(int n, int p, int q)
{
    // if bits are different at position `p` and `q`
    int bitAtP = (n & (1 << p)) >> p;
    int bitAtQ = (n & (1 << q)) >> q;
    if (bitAtP ^ bitAtQ)
    {
        n ^= (1 << p);
        n ^= (1 << q);
    }
    return n;
}

void print(int value) 
{
    for (int i = 0; i<8; i++) {
        if (value & (MASK_8_BIT >> i)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
}
 
int main()
{
    int n = 5;
    int p = 1, q = 2;    // swap 3rd and 7th bit from the right
    
    printf("Value Before Swap : \n");
    print(n);
    n = swap (n, p, q);

    printf("Value After Swap : \n");
    print(n);

    return 0;
}
