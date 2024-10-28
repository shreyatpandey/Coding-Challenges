#include <stdio.h>
#include <stdlib.h>

int flipsBitsToConvert(int num1, int num2) {
    int count = 0;
    for (int product = num1 ^ num2; product != 0; product = product & (product-1))
    {
        count += 1;
    }
    return count;
}

void binaryprint(int num) {
    printf("num:%d\n", num);
    for(int i=0; i < 8; i++) {
        if (num & (0x80 >>i)) {
            printf("1");
        }
        else {
            printf("0");
        }
    }
    printf("\n");
    return ;
}

int main() {
    printf("Test-Case-1:\n");
    binaryprint(2);
    binaryprint(3);
    printf("2 and 3:%d\n", flipsBitsToConvert(2, 3));
    printf("Test-Case-2:\n");
    binaryprint(29);
    binaryprint(15);
    printf("29 and 15: %d\n", flipsBitsToConvert(29,15));
    return 0;
}