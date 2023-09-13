'''
TC:- O(n)
SC:- O(n)
Never Accepted
'''
class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        :type s: str
        :rtype: bool
        """
        string = ''
        for char in s:
            if char.isalpha() or char.isdigit():
                string += char.lower()
        midLength = len(string)//2
        for j in range(0,midLength):
            if string[j] != string[len(string)-1-j] :
                return False
        return True



'''
TC:- O(n)
SC:- O(1)
'''
'''
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

'''
class Solution:
    def isPalindrome(self, s: str) -> bool:
        """
        :type s: str
        :rtype: bool
        """
        left,right = 0,len(s)-1
        while left < right:
            if not s[left].isalnum():
                left += 1
                continue
            if not s[right].isalnum():
                right -=1
                continue
            if s[right].lower() != s[left].lower():
                return False
            left += 1
            right -=1
        return True
