'''
Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:

|a - x| < |b - x|, or
|a - x| == |b - x| and a < b
 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
'''

'''
Complexity
Tc:- O(log(n))
Sc:- O(1)
'''
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        if len(arr) <= k: return arr
        left, right = 0, len(arr) - k - 1
        while left <= right: 
            mid = (right+left)//2
            if x - arr[mid] > arr[mid + k] - x:
                left = mid + 1
            else: 
                right = mid - 1
        return arr[left:left+k]
