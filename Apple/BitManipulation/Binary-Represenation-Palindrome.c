/*
Using reverse bits method will not give you the right
solution
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool is_binary_palindrome(int num) {
    int rev_binary = 0;
    int copy_num = num;
    while (copy_num) {
        rev_binary = (rev_binary << 1) | (copy_num & 1);
        printf("rev_binary:%d\n", rev_binary);
        copy_num >>= 1;
    }
    printf("%d\n", rev_binary);
    return rev_binary == num;
}
int main() {
    printf("=== Test Case - 1 ===\n");
    int input = 5;
    is_binary_palindrome(input);

    printf("=== Test Case - 2 === \n");
    input = 9;
    is_binary_palindrome(input);

    printf("=== Test Case - 3 === \n");
    input = 10;
    is_binary_palindrome(input);

    return 0;
}