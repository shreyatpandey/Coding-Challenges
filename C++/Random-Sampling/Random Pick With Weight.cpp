/*
You are given an array of positive integers w where w[i] describes the weight of ith index (0-indexed).

We need to call the function pickIndex() which randomly returns an integer in the range [0, w.length - 1]. 
pickIndex() should return the integer proportional to its weight in the w array. For example, for w = [1, 3], the probability of picking the index 0 is 1 / (1 + 3) = 0.25 (i.e 25%) while the probability of picking the index 1 is 3 / (1 + 3) = 0.75 (i.e 75%).

More formally, the probability of picking index i is w[i] / sum(w).

 Input
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output
[null,1,1,1,1,0]

Explanation
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // return 1. It's returning the second element (index = 1) that has probability of 3/4.
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 1
solution.pickIndex(); // return 0. It's returning the first element (index = 0) that has probability of 1/4.
*/
class Solution {
    private:
        vector<int>SumOfWeights;
public:
    Solution(vector<int>& w) {
        int sum  = 0;
        for( int num:w)
        {
            sum += num ;
            SumOfWeights.emplace_back(sum);
        }
        
    }
    
    int pickIndex() {
        int RandomNumber = (int)(SumOfWeights[SumOfWeights.size()-1]*((double)rand()/(RAND_MAX)));
        for(int i =0;i<SumOfWeights.size();i++)
        {
            if ( RandomNumber < SumOfWeights[i] )
                return i;
        }
        return 0;   
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
