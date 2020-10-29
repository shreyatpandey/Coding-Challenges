class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        list_split_string = s.split()
        return (' '.join(reversed(list_split_string)))
