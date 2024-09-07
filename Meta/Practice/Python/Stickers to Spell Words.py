'''
We are given n different types of stickers. Each sticker has a lowercase English word on it.

You would like to spell out the given string target by cutting individual letters from your collection of stickers and rearranging them. 
You can use each sticker more than once if you want, and you have infinite quantities of each sticker.

Return the minimum number of stickers that you need to spell out target. If the task is impossible, return -1.
'''
'''
Input: stickers = ["with","example","science"], target = "thehat"
Output: 3
Explanation:
We can use 2 "with" stickers, and 1 "example" sticker.
After cutting and rearrange the letters of those stickers, we can form the target "thehat".
Also, this is the minimum number of stickers necessary to form the target string.
'''
'''
n == stickers.length
1 <= n <= 50
1 <= stickers[i].length <= 10
1 <= target.length <= 15
stickers[i] and target consist of lowercase English letters.
'''
'''
Complexity:-
Tc:- O(2^n)
SC:- O(n)
'''
class Solution:
    def minStickers(self, stickers: List[str], target: str) -> int:
        stickerCount = []
        for i,s in enumerate(stickers):
            stickerCount.append({})
            for c in s:
                stickerCount[i][c] = 1 + stickerCount[i].get(c,0)

        #print(stickerCount)
        dp = {}
        def dfs(t,stick):
            #print(dp)
            if t in dp:
                return dp[t]
            res = 1 if stick else 0
            remainT = ""
            for c in t:
                if c in stick and stick[c]>0:
                    stick[c] -= 1
                else:
                    remainT += c
            #print("remainT:",remainT)
            if remainT:
                used = float("inf")
                for s in stickerCount:
                    if remainT[0] not in s:
                        continue
                    used = min(used,dfs(remainT,s.copy()))
                    #print("used:",used)
                dp[remainT] = used
                res += used
            return res
        res = dfs(target,{})
        return res if res != float("inf") else -1
'''
Output:-
Test-Case:1
[{'w': 1, 'i': 1, 't': 1, 'h': 1}, {'e': 2, 'x': 1, 'a': 1, 'm': 1, 'p': 1, 'l': 1}, {'s': 1, 'c': 2, 'i': 1, 'e': 2, 'n': 1}]
dp: {}
remainT: thehat
dp: {}
remainT: ehat
dp: {}
remainT: ht
dp: {}
remainT: 
used: 1
used: 2
dp: {'ht': 1}
remainT: hat
dp: {'ht': 1}
remainT: a
dp: {'ht': 1}
remainT: 
used: 1
used: 2
used: 2
used: 3
'''
        

