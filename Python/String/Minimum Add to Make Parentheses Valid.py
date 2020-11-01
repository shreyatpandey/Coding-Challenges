'''
Python[20ms] work
'''
class Solution(object):
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        answer = balance = 0
        for symbol in S:
            if symbol == '(':
                balance += 1
            else:
                balance -= 1
            if balance == -1:
                answer += 1
                balance += 1
        return answer + balance
        
