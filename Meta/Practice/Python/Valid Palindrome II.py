'''
TC:- O(len(string))
SC:- O(1) as we are recurring only once, one the stack space is constant
'''
'''
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
'''
def validPalindrone(s):
  def isPalindrome(left, right, s, count):
    while left < right:
      if s[left] != s[right]:
        if count == 1:
          return False
        return isPalindrome(left + 1, right, s, count + 1) or isPalindrome(left, right - 1, s, count + 1)
      left += 1
      right -= 1
    return True

  return isPalindrome(0, len(s) - 1, s, 0)

'''
TC:- O(len(inputString))
SC:- O(1)
'''
class Solution:
    def validPalindrome(self, s: str) -> bool:
        i,j = 0,len(s)-1
        def checkPalindrome(index1,index2):
            while index1 < index2:
                if s[index1] != s[index2]:
                    return False
                index1 += 1
                index2 -= 1
            return True
    
        while i<j:
            if s[i] != s[j] :
                return checkPalindrome(i+1,j) or checkPalindrome(i,j-1)
            i += 1
            j -= 1
        
        return True

'''
TC:- O(len(inputString))
SC:- O(n)
'''

def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # Time: O(n)
        # Space: O(n)
        left, right = 0, len(s) - 1
        while left < right:
            if s[left] != s[right]:
                one, two = s[left:right], s[left + 1:right + 1]
                return one == one[::-1] or two == two[::-1]
            left, right = left + 1, right - 1
        return True
