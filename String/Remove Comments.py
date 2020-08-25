'''
Removal of Comments from C++ Problem

'''
class Solution(object):
    def removeComments(self, source):
        """
        :type source: List[str]
        :rtype: List[str]
        """
        CleanCode = []
        BlockComment = False
        for string in source:
            i = 0
            if  BlockComment == False :
                Code = []
            while i < len(string) :
                if string[i:i+2] == '/*' and BlockComment == False :
                    BlockComment = True
                    i += 1
                elif string[i:i+2] == '*/' and BlockComment :
                    BlockComment = False
                    i += 1
                elif string[i:i+2] == '//' and BlockComment == False :
                    break
                elif BlockComment == False :
                    Code.append(string[i])
                i += 1
            if Code and BlockComment == False :
                CleanString = "".join(Code)
                CleanCode.append(CleanString)
        
        return CleanCode
            
