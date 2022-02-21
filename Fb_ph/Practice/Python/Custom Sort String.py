'''
Time:- 45 ms
'''
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        result  = []
        for char in order:
            getCount = s.count(char)
            result.append(char*getCount)
        stringResult = "".join(result)
        for char in s:
            if char not in stringResult:
                getCount = s.count(char)
                stringResult += (char*getCount)
                
        return stringResult
      
 '''
 Time:- 43 ms
 '''
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        
        countCharacters = collections.Counter(s)
        result  = []
        for char in order:
            result.append(char*countCharacters[char])
            countCharacters[char] = 0
        
        for char in countCharacters:
            result.append(char*countCharacters[char])
            
        return "".join(result)
