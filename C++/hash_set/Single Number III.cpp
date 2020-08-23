/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]

*/
class Solution 
{
        private:
            map<int,int>frequencyofeachnumber;
            vector<int>storeresult;
            
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        for(auto num:nums)
        {
             if (frequencyofeachnumber.find(i) != frequencyofeachnumber.end())
            {
                frequencyofeachnumber[num]++;
            }
            else
            {
                frequencyofeachnumber[num] = 1;
            }
        }
       for(auto &num:frequencyofeachnumber)
        {
            if(num.second == 1)
                storeresult.emplace_back(num.first);
        }
        return storeresult;
    }
    
};
