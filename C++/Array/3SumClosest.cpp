class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int vectSize = nums.size();
        int Diff = INT_MAX;
        sort(nums.begin(),nums.end());
        int i = 0;
        while(i<vectSize-2)
        {
            int low = i + 1;
            int high = vectSize - 1;
            while(low<high)
            {
                int Sum = nums[i] + nums[low] + nums[high];
                if(abs(target-Sum)<abs(Diff))
                {
                    Diff = target - Sum;
                }
                if(Sum<target)
                {
                    low += 1;
                }
                else
                {
                    high -= 1;
                }
            }
            i += 1;
        }
        return target - Diff;
    }
};
