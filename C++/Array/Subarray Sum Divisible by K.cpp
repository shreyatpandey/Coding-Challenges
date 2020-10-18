/*
Problem Statement:
Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
    unordered_map<int, int>SumToModuloMap;
    int sum = 0;
    for (auto &x : A)
    {
        sum = (sum + x) % K;
        if (sum < 0)
            sum += K;
        SumToModuloMap[sum]++;
    }
    int count = 0;
    /* memorize this formula* = Prefix Counting*/
    for (auto &c : SumToModuloMap)
    {
        if (c.first != 0)
        {
            count += c.second * (c.second - 1) / 2;
        }
        else
        {
            count += (SumToModuloMap[0] + 1) * SumToModuloMap[0] / 2;
        }
    }
    return count;
        
    }
};
