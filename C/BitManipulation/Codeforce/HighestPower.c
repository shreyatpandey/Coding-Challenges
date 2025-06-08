#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Brainstorming: 
    1. Brian Kurnigham algorithm will not work.
    2. Count all the odd numbers in the given number factorial.
*/
/*
    Find the maximum value of k such that
    n & (n-1) & (n-2) & .... (k) = 0
*/
int maxValueK(int n) {
    // Find the highest power of 2 less than or equal to n
    int mask = 1;
    while (mask <= n) {
        mask <<= 1;
    }
    // The answer is mask/2 - 1
    return (mask >> 1) - 1;
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);
    int values = 0;
    for(int i = 0; i < test_cases; i++) {
        scanf("%d", &values);
        int result = maxValueK(values);
        printf("Result:%d\n", result);
        result = maxValueK2(values);
        printf("Result2:%d\n", result);
    }
    return 0;
}