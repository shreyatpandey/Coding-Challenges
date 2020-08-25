class Solution(object):
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        paragraph = paragraph.lower()
        list_words = re.findall(r'\w+',paragraph)
        words_dict = {}
        for i in range(0,len(list_words)):
            if list_words[i] in words_dict:
                words_dict[list_words[i]] += 1
            else:
                words_dict[list_words[i]] = 1
        
        for string_key in sorted(words_dict, key=words_dict.get, reverse=True):
            if string_key not in banned:
                return string_key
                
                
