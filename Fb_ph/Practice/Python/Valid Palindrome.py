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
