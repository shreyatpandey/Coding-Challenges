# The knows API is already defined for you.
# @param a, person a
# @param b, person b
# @return a boolean, whether a knows b
# def knows(a, b):

class Solution(object):
    def findCelebrity(self, n):
        """
        :type n: int
        :rtype: int
        """
        candidate = 0
        for i in range(1, n):
            if knows(candidate, i):  
                candidate = i      
    
        for i in range(n):
            candidate_knows_i = knows(candidate, i) 
            i_knows_candidate = knows(i, candidate) 
            if i != candidate and (candidate_knows_i or not i_knows_candidate):
                return -1
        return candidate
        
