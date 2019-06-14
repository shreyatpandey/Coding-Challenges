class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <2)
            return false;
        set<int>check_duplicates;
        for (int i=0;i<nums.size();i++)
        {
            if (check_duplicates.find(nums[i]) != check_duplicates.end())
            {
                return true;
            }
            check_duplicates.emplace(nums[i]);
        }
        return false;
    }
};
/*hare and Tortoise Method*/
int findDuplicate(int* nums, int numsSize){
    int slow = nums[0];
    int fast = nums[0];
    /* This will give intersection of slow and fast problems*/
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        printf("slow: %d\n",slow);
        printf("fast: %d\n",fast);
        
    } while (slow != fast);
    
        //Find the entrance of cycyle
        int ptr1 = nums[0];
        int ptr2 = slow;
        while (ptr1 != ptr2) 
        {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;

}
