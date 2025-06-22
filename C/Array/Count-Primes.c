#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Count the number of prime numbers that are strictly less than n
 * Uses the Sieve of Eratosthenes algorithm for efficiency
 * 
 * @param n: The upper limit (exclusive)
 * @return: Number of prime numbers less than n
 */
int countPrimes(int n) {
    if (n <= 2) {
        return 0;
    }
    
    // Create a boolean array "isPrime[0..n-1]" and initialize
    // all entries as true. A value in isPrime[i] will
    // finally be false if i is not a prime, else true.
    bool *isPrime = (bool*)malloc(n * sizeof(bool));
    if (isPrime == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    
    // Initialize all numbers as prime
    for (int i = 0; i < n; i++) {
        isPrime[i] = true;
    }
    
    // 0 and 1 are not prime numbers
    isPrime[0] = false;
    isPrime[1] = false;
    
    // Sieve of Eratosthenes
    for (int i = 2; i * i < n; i++) {
        // If isPrime[i] is not changed, then it is a prime
        if (isPrime[i]) {
            // Update all multiples of i
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    // Count the number of prime numbers
    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    
    free(isPrime);
    return count;
}

/**
 * Alternative implementation using trial division (less efficient for large n)
 * Useful for understanding the basic approach
 */
int countPrimesBasic(int n) {
    if (n <= 2) {
        return 0;
    }
    
    int count = 0;
    
    for (int i = 2; i < n; i++) {
        bool isPrime = true;
        
        // Check if i is prime by testing divisibility
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            count++;
        }
    }
    
    return count;
}

/**
 * Helper function to print all prime numbers less than n
 */
void printPrimes(int n) {
    printf("Prime numbers less than %d: ", n);
    
    for (int i = 2; i < n; i++) {
        bool isPrime = true;
        
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Please enter a non-negative number.\n");
        return 1;
    }
    
    printf("\nUsing Sieve of Eratosthenes:\n");
    int result = countPrimes(n);
    if (result >= 0) {
        printf("Number of prime numbers less than %d: %d\n", n, result);
    }
    
    printf("\nUsing basic trial division:\n");
    int result2 = countPrimesBasic(n);
    printf("Number of prime numbers less than %d: %d\n", n, result2);
    
    // Print the actual prime numbers for verification (if n is not too large)
    if (n <= 100) {
        printf("\n");
        printPrimes(n);
    }
    
    return 0;
}
