class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        temp = ""
        result = 0
        for char in s:
            if char not in temp:
                temp += char
                
            else:
                print("char:",char)
                char_index = temp.index(char) + 1
                print("char_index:",char_index)
                temp = temp[char_index:]
                print("temp:",temp)
                temp += char
            
            result = max(result,len(temp))
        
        return result
        
