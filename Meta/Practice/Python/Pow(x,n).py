'''
Constraints:

-100.0 < x < 100.0
-231 <= n <= 231-1
-104 <= xn <= 104

'''

'''
Wording:-
In multpilication , there is a repetitive word 
so for say 2^10 = 2^5.2^5
for x^n = x^n/2.x^n/2
To avoid duplicating work, we can keep dividing it by 2 and from above we can keep multiplying the number by itself
Question arises for say odd integer, and modification would be required to check if the power is odd or not
One way is recursion but the space complexity is O(n)
However we can still use bit operation as they are faster
'''

'''
TC:- O(Log2(N))
SC:- O(1)
'''
'''
Implement pow(x,n) which calculates x raised to the power n (i.e., xn)
'''
class Solution:
    def myPow(self, x, n):
        m = abs(n)
        ans = 1.0
        while m:
            if m & 1:
                ans *= x
            x *= x
            m >>= 1
        return ans if n >= 0 else 1 / ans
