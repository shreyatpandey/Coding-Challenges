class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        #print(zip(*strs))
        longest_matching_prefix = []
        for i in zip(*strs):
            #print (set(i))
            if len(set(i)) == 1:
                longest_matching_prefix.append(i[0])
            else:
                break
        return ("".join(longest_matching_prefix))
