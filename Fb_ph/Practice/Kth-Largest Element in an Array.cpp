// Time:  O(n) on average, using Median of Medians could achieve O(n) (Intro Select)
// Space: O(1)

// optimized for duplicated nums
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums, k - 1);
        return nums[k - 1];
    }
    
private:
    void nth_element(vector<int>& nums, int n) {
        int left = 0, right = size(nums) - 1;
        default_random_engine gen((random_device())());
        while (left <= right) {
            // Generates a random int in [left, right].
            uniform_int_distribution<int> dis(left, right);
            int pivot_idx = dis(gen);
            const auto& [pivot_left, pivot_right] = TriPartition(left, right, nums[pivot_idx], &nums);
            if (pivot_left <= n && n <= pivot_right) {
                return;
            } else if (pivot_left > n) {
                right = pivot_left - 1;
            } else {  // pivot_right < n.
                left = pivot_right + 1;
            }
        }
    }
    
    pair<int, int> TriPartition(int left, int right, int target, vector<int> *nums) {
        for (int mid = left; mid <= right;) {
            if ((*nums)[mid] == target) {
                ++mid;
            } else if ((*nums)[mid] > target) {
                swap((*nums)[left++], (*nums)[mid]);
                ++mid;
            } else {
                swap((*nums)[mid], (*nums)[right--]);
            }
        }
        return {left, right};
    }
};
