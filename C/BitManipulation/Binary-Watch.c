#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * A binary watch has 4 LEDs on the top to represent hours (0-11)
 * and 6 LEDs on the bottom to represent minutes (0-59).
 * Each LED represents a zero or one, with the least significant bit on the right.
 * Given an integer turnedOn which represents the number of LEDs that are currently on,
 * return all possible times the watch could represent.
 */

#define MAX_RESULTS 1000
#define TIME_STR_LEN 6

// Helper function to count set bits in a number
int countSetBits(int n) {
    int count = 0;
    while (n) {
        n = n & (n - 1);
        count++;
    }
    return count;
}

// Helper function to check if time is valid
int isValidTime(int hour, int minute) {
    return hour >= 0 && hour < 12 && minute >= 0 && minute < 60;
}

char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** result = (char**)malloc(MAX_RESULTS * sizeof(char*));
    *returnSize = 0;
    
    // Try all possible combinations of hours (0-11) and minutes (0-59)
    for (int hour = 0; hour < 12; hour++) {
        for (int minute = 0; minute < 60; minute++) {
            // Count bits in both hour and minute
            int totalBits = countSetBits(hour) + countSetBits(minute);
            
            // If total number of set bits equals turnedOn and time is valid
            if (totalBits == turnedOn && isValidTime(hour, minute)) {
                // Allocate memory for new time string
                result[*returnSize] = (char*)malloc(TIME_STR_LEN * sizeof(char));
                
                // Format time as "h:mm"
                sprintf(result[*returnSize], "%d:%02d", hour, minute);
                (*returnSize)++;
            }
        }
    }
    
    return result;
}

int main() {
    // Test cases
    int testCases[] = {1, 2, 9};
    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTestCases; i++) {
        int returnSize;
        char** times = readBinaryWatch(testCases[i], &returnSize);
        
        printf("\nPossible times with %d LED(s) turned on:\n", testCases[i]);
        for (int j = 0; j < returnSize; j++) {
            printf("%s ", times[j]);
            free(times[j]); // Free each string
        }
        printf("\n");
        
        free(times); // Free array of strings
    }
    
    return 0;
}