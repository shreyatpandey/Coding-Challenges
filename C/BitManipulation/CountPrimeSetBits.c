#include <stdio.h>
#include <stdbool.h>

// Function to count set bits in an integer
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Main function to count numbers with prime set bits
int countPrimeSetBits(int left, int right) {
    int result = 0;
    for (int i = left; i <= right; ++i) {
        int setBits = countSetBits(i);
        if (isPrime(setBits)) {
            result++;
        }
    }
    return result;
}

int main() {
    int left, right;
    printf("Enter left and right: ");
    scanf("%d %d", &left, &right);
    int ans = countPrimeSetBits(left, right);
    printf("Count of numbers with prime set bits: %d\n", ans);
    return 0;
}
