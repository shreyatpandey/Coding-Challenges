#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        if (nums.size() < 2)
        {
           return result;
        }
       
        sort(nums.begin(),nums.end());
        int i=0;
        while(i < nums.size() - 2)
        {
             int j,k;
            vector<int>loop;
             if (i == 0  || nums[i] != nums[i - 1])
             {
                  j = i + 1;
                  k = nums.size() - 1;
                 while (j<k)
                 {
                     int sum = nums[i] + nums[j] + nums[k] ;
                      if (sum < 0)
                      {
                          j += 1;
                      }
                     else if (sum > 0)
                     {
                         k -= 1;
                     }
                     else
                     {

                         loop = {nums[i],nums[j],nums[k]};
                         result.push_back(loop);
                     
                     j += 1;
                     k -= 1;
                     while(j<k && nums[j] == nums[j-1])
                     {
                         j += 1;
                     }
                     while(j<k && nums[k] == nums[k+1])
                     {
                         k -= 1;
                     }
                    }
                 }
             }
                i += 1;
                 
            }
        return result;
        
    }
};
