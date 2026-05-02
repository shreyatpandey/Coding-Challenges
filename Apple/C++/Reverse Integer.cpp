/*
Reverse a 32-bit Integer

Asking-Questions:-
(1) Do I need to take care of overflow?
(2) Does the system support 64-bit integer?
Is it algorithm knowledge vs computer knowledge?

Is long allowed to use?
*/
#define INTMAX 2147483647
#define INTMIN -2147483648

class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INTMAX/10 || (rev == INTMAX / 10 && pop > 7)) return 0; // This is to handle the overflow case for INT_MAX
            if (rev < INTMIN/10 || (rev == INTMIN / 10 && pop < -8)) return 0; // This is to handle the overflow case for INT_MIN
            rev = rev * 10 + pop;
        }
        return rev;
        
    }
};
