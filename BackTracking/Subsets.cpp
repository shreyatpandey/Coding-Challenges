class Solution {
    private:
        void Permute(vector<int>&nums,vector<int>&current,vector<vector<int>>&Result,int left,int right);
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int LengthVector = nums.size();
        vector<int>current;
        vector<vector<int>>Result;
        Permute(nums,current,Result,0,LengthVector-1);
        return Result;
        
    }
};
void Solution::Permute(vector<int>&nums,vector<int>&current,vector<vector<int>>&Result,int left,int right)
{
        Result.emplace_back(current);
        for(int i=left;i<=right;i++)
        {
            current.emplace_back(nums[i]);
            Permute(nums,current,Result,i+1,right);
            current.pop_back();
        }
    
    
    
}
