/*
TC:- O(m+n)
where m is the length of first array and n is the length of second array
SC:- O(m+n)
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int>check_intersection;
        vector<int>result;
        for(int i=0;i<nums1.size();i++)
        {
            check_intersection.emplace(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if (check_intersection.find(nums2[i]) != check_intersection.end())
            {
                if ( !(find(result.begin(),result.end(),nums2[i]) != result.end()))
                    result.emplace_back(nums2[i]);
            }
        }
        return result;
        
    }
};
