
#include <iostream>
#include <bitset>
using namespace std;
// Function to swap bits at position `p` and `q` in integer `n`
int swap(int n, int p, int q)
{
    // if bits are different at position `p` and `q`
    if (((n & (1 << p)) >> p) ^ ((n & (1 << q)) >> q))
    {
        n ^= (1 << p);
        n ^= (1 << q);
    }
    return n;
}
 
int main()
{
    int n = 31;
    int p = 2, q = 6;    // swap 3rd and 7th bit from the right
 
    cout << n << " in binary is " << bitset<8>(n) << endl;
    n = swap (n, p, q);
    cout << n << " in binary is " << bitset<8>(n) << endl;
 
    return 0;
}
