#include <stdio.h>

// Function to count set bits in an integer
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    int x;
    printf("Enter the number of bacteria you want to see: ");
    scanf("%d", &x);
    int result = countSetBits(x);
    printf("Minimum number of bacteria needed: %d\n", result);
    return 0;
}
