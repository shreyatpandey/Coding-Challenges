/*
TC:- O(NLog(N))
Space-Complextiry:- O(1)
*/
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Time O(NlogN) Space O(1)
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> intersections;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                intersections.push_back(nums1[i]);
                i++;
                j++;
                while (i < nums1.size() && nums1[i] == nums1[i - 1]) {
                    i++;
                }
                while (j < nums2.size() && nums2[j] == nums2[j - 1]) {
                    j++;
                }
            }
        }
        return intersections;
    }
