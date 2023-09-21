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
            if t in dp:
                return dp[t]
            res = 1 if stick else 0
            remainT = ""
            for c in t:
                if c in stick and stick[c]>0:
                    stick[c] -= 1
                else:
                    remainT += c
            if remainT:
                used = float("inf")
                for s in stickerCount:
                    if remainT[0] not in s:
                        continue
                    used = min(used,dfs(remainT,s.copy()))
                dp[remainT] = used
                res += used
            return res
        res = dfs(target,{})
        return res if res != float("inf") else -1
        

