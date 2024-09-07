'''
The array-form of an integer num is an array representing its digits in left to right order.
For example, for num = 1321, the array form is [1,3,2,1].
Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
Example 1:

Input: num = [1,2,0,0], k = 34
Output: [1,2,3,4]
Explanation: 1200 + 34 = 1234
'''

'''
TC:- O(max(N,logK))
SC:- O(max(N.logK))
'''
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        for i in range(len(A) - 1, -1, -1):
            if not K: 
                break
            K, A[i] = divmod(A[i] + K, 10)
        while K:
            K, a = divmod(K, 10)
            A = [a] + A #this is nothing but insert into front:- A.insert(0,a)
        return A
