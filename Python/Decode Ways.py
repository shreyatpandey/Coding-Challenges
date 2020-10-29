class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0 or s[0] == '0':
            return 0
        previous, previous_to_previous = 1, 1
        for i in range(1,len(s)):
            if s[i] != '0':
                x = previous
            else : 
                x = 0 
            if int(s[i - 1: i + 1]) < 27 and s[i - 1] != '0':
                y = previous_to_previous
            else : 
                y = 0
            previous = x + y
            previous_to_previous = x
        
        return previous

        
