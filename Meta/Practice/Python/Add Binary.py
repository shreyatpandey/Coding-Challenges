'''
TC:- O(max(len(a),len()b))
SC:- O(max(len(a),len(b))
'''
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        n = max(len(a), len(b))
        a, b = a.zfill(n), b.zfill(n)
        
        carry = 0
        answer = []
        for i in range(n - 1, -1, -1):
            if a[i] == '1':
                carry += 1
            if b[i] == '1':
                carry += 1
                
            if carry % 2 == 1:
                answer.append('1')
            else:
                answer.append('0')
            
            carry //= 2
        
        if carry == 1:
            answer.append('1')
        answer.reverse()
        
        return ''.join(answer)
'''
Give this apporach only when asked 
TC same as above
'''
'''
Algorithm

Convert a and b into integers x and y, x will be used to keep an answer, and y for the carry.

While carry is nonzero: y != 0:

Current answer without carry is XOR of x and y: answer = x^y.

Current carry is left-shifted AND of x and y: carry = (x & y) << 1.

Job is done, prepare the next loop: x = answer, y = carry.

Return x in the binary form.

'''
class Solution:
    def addBinary(self, a, b) -> str:
        x, y = int(a, 2), int(b, 2)
        while y:
            answer = x ^ y
            carry = (x & y) << 1
            x, y = answer, carry
        return bin(x)[2:]
