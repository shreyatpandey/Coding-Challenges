// TC:- O(log(N))
//SC:- O(1)
// Approach:- Brian Kernighan Algorithm
class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t noOfOneBits = 0;
        while(n)
        {
            n = n&(n-1);
            noOfOneBits += 1;
        }
        return noOfOneBits;
        
    }
};
