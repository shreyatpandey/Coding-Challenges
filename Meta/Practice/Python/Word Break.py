'''
Note the same word in word dict would be used multiple times
the max size of the wordDict would be smaller than the s
'''
'''
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
'''
'''
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
'''

'''
Approach: BFS
Tc:- O(n^3)
SC:- O(n)
'''
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        q = deque([s])
        seen = set() 
        while q:
            s = q.popleft()    # popleft() = BFS ; pop() = DFS
            for word in wordDict:
                if s.startswith(word):
                    new_s = s[len(word):]
                    if new_s == "": 
                        return True
                    if new_s not in seen:
                        q.append(new_s)
                        seen.add(new_s)
        return False
'''
Approach: DFS
Tc:- O(n^3)
SC:- O(n)
'''
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        @lru_cache
        def helper(i):
            if not s[i:]: return True
            for word in wordDict:
                if s[i:].startswith(word) and helper(i + len(word)):
                    return True
            return False
        return helper(0)
'''
 Approach:- bottom-Up
 TC:- O(m.n)
 SC:- O(len(s)) which is the space occupied by the 1-D Dp matrix
 Decision Tree->Cache->DP
 Key is to first check whether the prefix in s startswith the first word in the wordDict
 
 "leetcode , ["leet","code"]
 i = 0 , i=4 are two important index as i = 0 is l for leet and i = 4 for code
 dp[8] = True in leetcode as the length is 8
 dp[0+len(w}] = True
'''
def wordBreak(s,wordDict):
    dp = [False]*(len(s)+1)
    dp[len(s)] = True #Base Case
    for i in range(len(s)-1,-1,-1):
        for w in wordDict:
            if(i+len(w))<=len(s) and s[i:i+len(w)] == w:
                dp[i] = dp[i+len(w)]
                print("i,dp:",i,dp)
            if dp[i] == True:
                print("True")
                break
    return dp[0]

'''
Stack-Trace:-
Test-Case-1
s[i;i+len(w)] e
s[i;i+len(w)] e
s[i;i+len(w)] de
s[i;i+len(w)] de
s[i;i+len(w)] ode
s[i;i+len(w)] ode
s[i;i+len(w)] code
s[i;i+len(w)] code
i,dp: 4 [False, False, False, False, True, False, False, False, True]
True
s[i;i+len(w)] tcod
s[i;i+len(w)] tcod
s[i;i+len(w)] etco
s[i;i+len(w)] etco
s[i;i+len(w)] eetc
s[i;i+len(w)] eetc
s[i;i+len(w)] leet
i,dp: 0 [True, False, False, False, True, False, False, False, True]
True
'''
                
