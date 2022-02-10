class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        i,j = 0,0
        while i<len(word) and j<len(abbr):
            if abbr[j].isnumeric():
                if abbr[j] == '0':
                    return False
                num = 0
                while j < len(abbr) and abbr[j].isnumeric():
                    num = num*10 + int(abbr[j])
                    j += 1
                #get the index
                i += num
            else:
                if abbr[j] != word[i] :
                    return False
                i += 1
                j += 1
        return i == len(word) and j== len(abbr)
     
s = Solution()
print("TestCase-1:")
print(s.validWordAbbreviation("internationalization","i12iz4n"))
print("TestCase-2:")
print(s.validWordAbbreviation("apple","a2e"))
print("TestCase-3:")
print(s.validWordAbbreviation("a","01"))

