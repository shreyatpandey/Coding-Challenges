public class SquareOfSortedArray {
    /* Runtime Complexity: O(n)
     * Space Complexity: O(n)
     * This function takes a sorted array of integers and returns a new array
     * containing the squares of each number, also sorted in non-decreasing order.
     */
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int left = 0, right = n - 1;
        int index = n - 1;

        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];

            if (leftSquare > rightSquare) {
                result[index--] = leftSquare;
                left++;
            } else {
                result[index--] = rightSquare;
                right--;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        SquareOfSortedArray solution = new SquareOfSortedArray();

        // Test Case 1: Basic case with few elements
        int[] nums1 = {-4, -1, 0, 3, 10};
        System.out.println("Test Case 1: " + java.util.Arrays.toString(solution.sortedSquares(nums1))); // Expected: [0, 1, 9, 16, 100]

        // Test Case 2: All negative numbers
        int[] nums2 = {-7, -3, -1};
        System.out.println("Test Case 2: " + java.util.Arrays.toString(solution.sortedSquares(nums2))); // Expected: [1, 9, 49]

        // Test Case 3: All positive numbers
        int[] nums3 = {2, 3, 5};
        System.out.println("Test Case 3: " + java.util.Arrays.toString(solution.sortedSquares(nums3))); // Expected: [4, 9, 25]

        // Test Case 4: Mixed negative and positive numbers
        int[] nums4 = {-5, -3, -2, 0, 1, 4};
        System.out.println("Test Case 4: " + java.util.Arrays.toString(solution.sortedSquares(nums4))); // Expected: [0, 1, 4, 9, 16, 25]

        // Test Case 5: Single element array
        int[] nums5 = {0};
        System.out.println("Test Case 5: " + java.util.Arrays.toString(solution.sortedSquares(nums5))); // Expected: [0]

        // Test Case 6: Large array with mixed values
        int[] nums6 = {-10, -5, -2, 0, 3, 6, 9};
        System.out.println("Test Case 6: " + java.util.Arrays.toString(solution.sortedSquares(nums6))); // Expected: [0, 4, 9, 25, 36, 100, 121]
    }

}
