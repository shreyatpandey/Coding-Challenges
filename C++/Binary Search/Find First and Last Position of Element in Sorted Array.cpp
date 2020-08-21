class Solution {
    private:
        int LeftIndexElement ( vector<int>&nums,int target, bool left) ;
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>TargetRange = {-1,-1};
        
        int LeftIndex = LeftIndexElement ( nums , target, true);
        if ( LeftIndex == nums.size() || nums[LeftIndex] != target)
        {
            return TargetRange ;
        }
        TargetRange[0] = LeftIndex ;
        TargetRange[1] = LeftIndexElement ( nums , target , false)-1;
        return TargetRange ;
        
    }
};
int Solution :: LeftIndexElement ( vector<int>&nums,int target, bool left)
{
    int low = 0;
    int high = nums.size() ;
    while(low<high)
    {
        int midvalue = (low + high)/2;
        if ( nums[midvalue] > target || (left && nums[midvalue] == target))
        {
            high = midvalue;
        }
        else
        {
            low = midvalue + 1;
        }
    }
    return low;
}
