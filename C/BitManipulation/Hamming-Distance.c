/*
 The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
 Given two integers x and y, return the Hamming distance between them.
 Example 1:

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
Example 2:

Input: x = 3, y = 1
Output: 1

*/

#include <stdio.h>

// Function to calculate Hamming distance between two integers
int hammingDistance(int x, int y) {
    int xor = x ^ y;
    int distance = 0;
    while (xor) {
        distance += xor & 1;
        xor >>= 1;
    }
    return distance;
}

int main() {
    int x = 1, y = 4;
    printf("Hamming distance between %d and %d is %d\n", x, y, hammingDistance(x, y));
    // You can test with other values as well
    return 0;
}
