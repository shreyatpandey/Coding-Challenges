'''
Input = "bb"
Output = 3

Input = "aaa"
Output = 6
'''
'''
Approach:- Expansion around centers
TC:- O(n^2)
There are total of 2N-1 possible centers and each center can possibly expand to N which is the length of the string
So, in total we have = N.(2N-1)  ~ N^2
SC:- O(1)
'''\
class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        n = len(s)
        if n==0:return 0
        for i in range(n):
            count+=1
            left, right = i-1, i+1
            while right< n and s[right] == s[i]:
                right+=1
                count+=1
            
            while left>=0 and right<n and s[left] == s[right]:
                count+=1
                left-=1
                right+=1
        return count
