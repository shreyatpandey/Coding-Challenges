/*Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string.
If there are less than k characters left, reverse all of them. 
If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
Example:
Input: s = "abcdefg", k = 2
Output: "bacdfeg"*/


class Solution(object):
    def reverseStr(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        list_split_string = list(s)
        for i in range(0,len(s),2*k):
            list_new = list(s[i:i+k])
            list_new.reverse()
            list_split_string[i:i+k] = list_new
            
        return "".join(list_split_string)
