#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;

void print(unsigned char byte)
{
     for (int i = 7; i >= 0; i--) {
        int b = byte >> i;
        if (b & 1)
            cout << "1";
        else
            cout << "0";
    }
}

int main()
{
  unsigned char bytes[4];
  unsigned long n = 10;

  bytes[0] = (n >> 24) & 0xFF;
  bytes[1] = (n >> 16) & 0xFF;
  bytes[2] = (n >> 8) & 0xFF;
  bytes[3] = (n >> 0) & 0xFF;

  cout << "Integer: " << n << endl;

  cout << "Byte Array: ";


  for(int i = 0; i < 4; i++){
    print(bytes[i]);
    cout << "\t";
  }
}
