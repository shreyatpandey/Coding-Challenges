'''
Wording:-
Explanation of Input:-
(1) s = "aa" , p = "a"
If '*' or '.' it is as good as string match

(2)
'.' - period can be any character
'ab' = 'a.' as '.' can take any character

(3) s = "aa" , p ="a*"
p can repeat infinite times as = ["","a","aa","aaa","aaaaa"]

(4) ".*" <=> ["",".","..","..."] and "." can represent any character

The complexity comes from the "*" and "." as dot simply represents any character

Basic Intuitive Approach is to develop a Decision tree
say for a* two choices "",a -> "aa","" and TC:- O(2^n)
If we cache this, then we would bring down this TC:- O(M*N)

Whenever we encounter "*", either I can use the star or not use the star
If we choose not to use the star, we would increment the j pointer by 2 that is j = j +2

Question:-
What is p is out of bound with respect to the length of the string = s
Consecutively, what if s is out of bound with respect to the length of string = p

'''
'''
Top-Down - Memoization
TC:- O(M*N)
where M is the length of string = s and N is the length of string = p
SC:- O(M*N)
'''
class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        cache = {}
        def dfs(i,j):
            if (i,j) in cache:
                return cache[(i,j)]
            
            if i>=len(s) and j>=len(p):
                return True
            
            if j>=len(p):
                return False
            
            match = i<len(s) and (s[i]==p[j] or p[j] == '.')
            if (j+1)<len(p) and p[j+1] == '*' :   #the reason for checking "*" is that it has the highesh precedence and j+1 because the firsr character can never be "*"
                #whenever we encounter "*" we have two choices use or dont use it
                cache[(i,j)] = (dfs(i,j+2) or  #dont use *
                        (match and dfs(i+1,j))) #use *
                return cache[(i,j)]
            if match:
                cache[(i,j)] = dfs(i+1,j+1)
                return cache[(i,j)]
            cache[(i,j)] = False
            return False
        
        return dfs(0,0)
        
