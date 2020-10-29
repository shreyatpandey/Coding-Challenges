class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        list_string_split = s.split()
        for i in range(0,len(list_string_split)):
            list_string_split[i] = list_string_split[i][::-1]
        
        return ' '.join(list_string_split)
        
