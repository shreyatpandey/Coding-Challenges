//TC:- O(n)
//SC:- O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>Right(nums.size(),0);
        vector<int>Left(nums.size(),0);
        vector<int>Result(nums.size(),0);
        Left[0] = 1;
        Right[nums.size()-1] = 1 ;
        //Calculation of Left Array
        for(int i=1;i<nums.size();i++)
        {
            Left[i] = nums[i-1]*Left[i-1];
        }
        
        
        for(int j=nums.size()-2;j>=0;j--)
        {
            Right[j] = nums[j+1]*Right[j+1];
        }
        
        for(int i=0;i<nums.size();i++)
        {
            Result[i] = Left[i]*Right[i];
        }
       
        return Result;
        
        
    }
};
