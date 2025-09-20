package Java;

class MinimumSwapToGroupOnes {
    public int minSwaps(int[] nums) {
        int totalOnes = 0;
        for (int num : nums) {
            if (num == 1) {
                totalOnes++;
            }
        }

        if (totalOnes == 0 || totalOnes == nums.length) {
            return 0;
        }

        int currentOnes = 0;
        for (int i = 0; i < totalOnes; i++) {
            if (nums[i] == 1) {
                currentOnes++;
            }
        }

        int maxOnesInWindow = currentOnes;
        for (int i = totalOnes; i < nums.length; i++) {
            if (nums[i] == 1) {
                currentOnes++;
            }
            if (nums[i - totalOnes] == 1) {
                currentOnes--;
            }
            maxOnesInWindow = Math.max(maxOnesInWindow, currentOnes);
        }

        return totalOnes - maxOnesInWindow;
    }

    public static void main(String[] args) {    
        MinimumSwapToGroupOnes solution = new MinimumSwapToGroupOnes();
        
        // Test Case 1: Basic case with few elements
        int[] nums1 = {1, 1, 2};
        System.out.println("Test Case 1: " + solution.minSwaps(nums1)); // Expected: 2
        
        // Test Case 2: Larger array with multiple ones
        int[] nums2 = {1, 1, 1, 2, 2, 3};
        System.out.println("Test Case 2: " + solution.minSwaps(nums2)); // Expected: 0
        
        // Test Case 3: Array with all ones
        int[] nums3 = {1, 1, 1, 1};
        System.out.println("Test Case 3: " + solution.minSwaps(nums3)); // Expected: 0
        
        // Test Case 4: Array with no ones
        int[] nums4 = {0, 0, 0, 0};
        System.out.println("Test Case 4: " + solution.minSwaps(nums4)); // Expected: 0
        
        // Test Case 5: Array with alternating ones and zeros
        int[] nums5 = {1, 0, 1, 0, 1, 0};
        System.out.println("Test Case 5: " + solution.minSwaps(nums5)); // Expected: 2
        
        // Test Case 6: Array with ones at the ends
        int[] nums6 = {1, 0, 0, 0, 1};
        System.out.println("Test Case 6: " + solution.minSwaps(nums6)); // Expected: 1
        
        // Test Case 7: Large array with scattered ones
        int[] nums7 = {1, 0, 0, 1, 0, 0, 1, 0, 1, 1};
        System.out.println("Test Case 7: " + solution.minSwaps(nums7)); // Expected: 3
    }
}