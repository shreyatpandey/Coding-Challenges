//TC:- O(m+n) where m is the length of first list , n is the length of second list
//SC:- O(1) as we are inserting in-space in the first list

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
        while(i>=0)
        {
            nums1[k--] = nums1[i--];
        }
        while(j>=0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};
