'''
Complexity:-
Tc:- O(n)
we are iterating over the string once
Sc:- O(k)
we don't count the output as part of the space complexity, but for each word, 
we are using some space for the length and delimiter
'''
class Codec:
    def encode(self, strs: List[str]) -> str:
        """Encodes a list of strings to a single string.
        """
        res = ""
        for strings in strs:
            res += str(len(strings)) + "#" + strings
        return res
        

    def decode(self, s: str) -> List[str]:
        """Decodes a single string to a list of strings.
        """
        Result, i = [], 0
        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1
            length = int(s[i:j])
            Result.append(s[j+1:j+1+ length])
            i = j+1+length
        return Result

        
