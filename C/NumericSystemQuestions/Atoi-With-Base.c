#include<stdio.h>
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// TC: O(1) - constant time character conversion
// SC: O(1) - no extra space used
int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
 
// TC: O(n) - where n is length of input string (strlen + loop through all characters)
// SC: O(1) - only uses constant extra space for local variables
// Function to convert a number from given base 'b'
// to decimal
int toDeci(char *str, int base)
{
    int len = strlen(str);
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;
 
    // Decimal equivalent is str[len-1]*1 +
    // str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (val(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
 
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}
 
// Driver code
int main()
{
    char str[] = "11A";
    int base = 16;
    printf("Decimal equivalent of %s in base %d is "
           " %d\n", str, base, toDeci(str, base));
    return 0;
}
