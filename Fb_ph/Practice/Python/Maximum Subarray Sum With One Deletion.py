'''
Given an array of integers,
return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. 
In other words, you want to choose a subarray and 
optionally delete one element from it so that there is still at least one element left and the sum of the remaining elements is maximum possible.
Note that the subarray needs to be non-empty after deleting one element.
'''
'''
Constraints:
1 <= arr.length <= 105
-104 <= arr[i] <= 104
'''
'''
Example 1:
Input: arr = [1,-2,0,3]
Output: 4
Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the subarray [1, 0, 3] becomes the maximum value.
Example 2:
Input: arr = [1,-2,-2,3]
Output: 3
Explanation: We just choose [3] and it's the maximum sum.
'''
'''
Explanation of the code:-
Keep two array's one will have prefix sum ending at that index from start and 
one will have prefix sum ending at that index from end, using kadane's algorithm. 
For each i these array's will denote maximum subarray ending at i-1 and 
maximum subarray starting at i+1 so when you add these two values it will denote maximum subarray after deleting i.
'''
class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        n = len(arr)
        #maximum subarray starting from the last element i.e. backwards 
        prefix_sum_ending = [float('-inf')]*n
        #maximum subarray starting from the first element i.e forwards
        prefix_sum_starting = [float('-inf')]*n
        prefix_sum_ending[n-1] = arr[n-1]
        prefix_sum_starting[0] = arr[0]
        
        for i in range(1,n):
            prefix_sum_starting[i] = max(prefix_sum_starting[i-1]+arr[i], arr[i])
        for i in range(n-2,-1,-1):
            prefix_sum_ending[i] = max(prefix_sum_ending[i+1]+arr[i], arr[i])
           
        max_without_deletion = max(prefix_sum_starting)
        max_with_deletion = float('-inf')
        for i in range(1,n-1):
            max_with_deletion = max(max_with_deletion, prefix_sum_starting[i-1]+prefix_sum_ending[i+1])
            
        return max(max_without_deletion, max_with_deletion)

