#include <stdio.h>

int minFlips(int a, int b, int c) {
    int flips = 0;
    for (int i = 0; i < 32; ++i) {
        int abit = (a >> i) & 1;
        int bbit = (b >> i) & 1;
        int cbit = (c >> i) & 1;
        if ((abit | bbit) == cbit) {
            continue;
        }
        if (cbit == 1) {
            // Both abit and bbit are 0, need 1 flip
            flips += 1;
        } else {
            // cbit == 0, need to flip all 1s in a and b at this bit
            flips += abit + bbit;
        }
    }
    return flips;
}

int main() {
    int a, b, c;
    printf("Enter a, b, c: ");
    scanf("%d %d %d", &a, &b, &c);
    int result = minFlips(a, b, c);
    printf("Minimum flips required: %d\n", result);
    return 0;
}
