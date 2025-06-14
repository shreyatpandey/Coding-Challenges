#include <stdio.h>

int minSwapsToGroupOnes(int arr[], int n) {
    int totalOnes = 0;

    // Count the total number of 1's in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            totalOnes++;
        }
    }

    // If there are no 1's or all are 1's, no swaps are needed
    if (totalOnes == 0 || totalOnes == n) {
        return 0;
    }

    // Find the minimum number of 0's in a window of size totalOnes
    int minSwaps = n; // Initialize to a large value
    int currentZeros = 0;

    // Count zeros in the first window
    for (int i = 0; i < totalOnes; i++) {
        if (arr[i] == 0) {
            currentZeros++;
        }
    }

    minSwaps = currentZeros;

    // Slide the window across the array
    for (int i = totalOnes; i < n; i++) {
        // Remove the element going out of the window
        if (arr[i - totalOnes] == 0) {
            currentZeros--;
        }

        // Add the element coming into the window
        if (arr[i] == 0) {
            currentZeros++;
        }

        // Update the minimum swaps
        if (currentZeros < minSwaps) {
            minSwaps = currentZeros;
        }
    }

    return minSwaps;
}

int main() {
    int arr[] = {1, 0, 1, 0, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = minSwapsToGroupOnes(arr, n);
    printf("Test Case -1 : %d\n", result);

    int arr2[] = {1, 1, 0, 0, 1, 1, 1, 0};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int result2 = minSwapsToGroupOnes(arr2, n2);
    printf("Test Case -2 : %d\n", result2);

    int arr3[] = {0, 0, 0, 0};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int result3 = minSwapsToGroupOnes(arr3, n3);
    printf("Test Case -3 : %d\n", result3);

    int arr4[] = {1, 1, 1, 1};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int result4 = minSwapsToGroupOnes(arr4, n4);
    printf("Test Case -4 : %d\n", result4);

    return 0;
}
