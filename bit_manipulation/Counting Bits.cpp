/*Apporach - 1: CountingNumber of Ones
TC:O(num*sizeofinteger)
SC: O(n)
*/
class Solution {
    private:
        int NumberOfOnes(int num);
public:
    vector<int> countBits(int num) {
        vector<int>result;
        for(int i=0;i<=num;i++)
        {
            result.push_back(NumberOfOnes(i));
        }
        return result;
    }
};
int Solution:: NumberOfOnes(int num)
{
    int CountSetBits = 0;
    while(num)
    {
        num = num&(num-1);
        CountSetBits += 1;
    }
    return CountSetBits;
}

/* Approach-2: DP with last setbit
TC: O(n)
SC: O(n)
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>result(num+1,0);
        for(int i=1;i<=num;i++)
        {
            result[i] = result[i&(i-1)]+1;
        }
        return result;
    }
};
