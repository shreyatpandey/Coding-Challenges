'''
Given an array of non-negative integers arr, you are initially positioned at start index of the array. 
When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.

Notice that you can not jump outside of the array at any time.

Example 1:
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 

Example 2:
Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
'''

'''
Constraints:
1 <= arr.length <= 5 * 104
0 <= arr[i] < arr.length
0 <= start < arr.length
'''
'''
Approach-1:- BFS
TC:- O(N) since we will visit every index at once
SC:- O(N)  
'''
from collections import deque
class Solution:
    def canReach(self, arr, start):
        _len_=len(arr)
        seen=set()
        queue=deque()
        queue.append(start)
        while(queue):
            idx=queue.popleft()
            if arr[idx]==0:
                return True
            seen.add(idx)
            for var in (idx-arr[idx],idx+arr[idx]):
                if (var not in seen) and (-1<var<_len_):
                    queue.append(var)
        return False
'''
Approach-2:- DFS
TC:- O(N)
SC:- O(N)
'''
from collections import deque
class Solution:
    def dfs(self,arr,idx,seen):
        if idx>=len(arr) or (idx<0) or (idx in seen):
            return False
        if arr[idx]==0:
            return True
        seen.add(idx)
        return self.dfs(arr,idx-arr[idx],seen) or self.dfs(arr,idx+arr[idx],seen)

    def canReach(self, arr, start):
        seen=set()
        return self.dfs(arr,start,seen)
