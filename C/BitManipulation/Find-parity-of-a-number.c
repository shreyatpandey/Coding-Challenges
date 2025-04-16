#include <stdio.h>
#include <stdint.h>

/*
    TC:- O(n)
    SC:- O(1)
*/
int find_parity(int n) {
  int parity = 0;
  while (n > 0) {
    parity ^= (n & 1);
    n >>= 1;
  }
  return parity;
}

/*
    TC:- O(log(n))
    SC:- O(1)
    Follow's Brian Kurnighan's Algorithm for set bits
*/
int find_parity_efficient(int n) {
  int parity = 0;
  while (n) {
    n &= (n - 1);
    parity ^= 1;
  }
  return parity;
}

/*
    TC:- O(1)
    SC:- O(1)
*/
int find_parity_most_efficient(uint32_t n) {
  n ^= n >> 16;
  n ^= n >> 8;
  n ^= n >> 4;
  n ^= n >> 2;
  n ^= n >> 1;
  return n & 1;
}

int main() {
  int number1 = 6;
  int parity1 = find_parity(number1);
  printf("The parity of %d is %s\n", number1, parity1 ? "odd" : "even");

  int number2 = 7;
  int parity2 = find_parity(number2);
  printf("The parity of %d is %s\n", number2, parity2 ? "odd" : "even");

  int number3 = 10;
  int parity3 = find_parity_efficient(number3);
  printf("The parity of %d using efficient method is %s\n", number3, parity3 ? "odd" : "even");

  int number4 = 15;
  int parity4 = find_parity_efficient(number4);
  printf("The parity of %d using efficient method is %s\n", number4, parity4 ? "odd" : "even");

  uint32_t number5 = 21;
  int parity5 = find_parity_most_efficient(number5);
  printf("The parity of %u using most efficient method is %s\n", number5, parity5 ? "odd" : "even");

  uint32_t number6 = 28;
  int parity6 = find_parity_most_efficient(number6);
  printf("The parity of %u using most efficient method is %s\n", number6, parity6 ? "odd" : "even");

  return 0;
}