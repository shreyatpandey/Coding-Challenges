'''
TC:- O(len(str))
SC:- O(1)

Input:- 1234
Output:- 1243

'''
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        n = [x for x in str(n)]
        # n = list(str(n))
        size = len(n)
        ans = -1
        for i in range(size-1,-1,-1):
            if n[i-1] < n[i] and i>0:
                if i == size-1 or n[-1]==n[i]: 
                    n[i-1], n[i]=n[i],n[i-1]
                    ans = int(''.join(n))
                    return -1 if ans > 2147483647 else ans
                else:
                    for j in range(size-1, i-1, -1):
                        if n[j]>n[i-1]:
                            n[i-1], n[j]=n[j],n[i-1]
                            break 
                    ans = int(''.join(n[:i]+n[i:][::-1]))
                return -1 if ans > 2147483647 else ans
        return ans
