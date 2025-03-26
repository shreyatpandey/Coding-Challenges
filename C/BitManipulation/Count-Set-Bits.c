#include <stdio.h>
#include <stdint.h>

/* TC:- O(log(n))
   SC :- O(1)
   Algo :- Brian Kurnighan's Algorithm
   Count the number of set bits in an integer
*/
int count_set_bits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}