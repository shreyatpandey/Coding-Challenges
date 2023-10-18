'''
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
'''
'''
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
'''
'''
Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
'''
'''
Complexity
Tc:- O(2^N)
Sorting take O(n*log(n))
Backtracking:- 
For each element in an array of size N, there are two possible combinations
2^N, either to include the number or exclude the number from the combination
Sc:- O(N)
For recursion stack space

'''
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates = sorted(candidates)
        self.dfs(candidates, target,[],res)
    
        return res
    
    def dfs(self,candidates, target, path, res):
        if target==0:
            res.append(path)
            return
        for i in range(len(candidates)):
            if candidates[i]>target:
                continue
            if i>=1 and candidates[i] == candidates[i-1]:
                continue
            self.dfs(candidates[i+1:],target-candidates[i],path+[candidates[i]],res)
