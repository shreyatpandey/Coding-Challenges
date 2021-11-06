class Solution(object):
    def maxLength(self, arr): #dont need backtrack
        """
        :type arr: List[str]
        :rtype: int
        """
        
        result = self.DFSTraversal(arr,0,"") 
        return result
 
        
    def DFSTraversal(self,arr,left,stringBuild): 
        if len(stringBuild) != len(set(stringBuild)) :#containsduplicatedcharacter
            return 0
        maxlen = len(stringBuild)
        for i in range(left,len(arr)): 
            stringLoop = stringBuild + arr[i]
            i += 1
            res = self.DFSTraversal(arr,i,stringLoop) 
            maxlen = max(res,maxlen)
        return maxlen
