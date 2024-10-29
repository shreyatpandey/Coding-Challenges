'''
Given a list of folders folder, return the folders after removing all sub-folders in those folders. 
You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of it. 
A sub-folder of folder[j] must start with folder[j], 
followed by a "/". For example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of "/a/b/c".

The format of a path is one or more concatenated strings of the form: 
'/' followed by one or more lowercase English letters.

For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string and "/" are not.
 

Example 1:

Input: folder = ["/a","/a/b","/c/d","/c/d/e","/c/f"]
Output: ["/a","/c/d","/c/f"]
Explanation: Folders "/a/b" is a subfolder of "/a" and "/c/d/e" is inside of folder "/c/d" in our filesystem.
'''

'''
Let N be the length of the folder and L maximum length of the folder path
Time Complexity :- 
O(n*l*log(n))

Space Complexity:-
O(n*l)
'''
class Solution(object):
    def removeSubfolders(self, folder):
        """
        :type folder: List[str]
        :rtype: List[str]
        """
        folder.sort()
        length = len(folder)
        Result = [folder[0]]
        
        for i in range(1,length) :
            last_folder = Result[-1]
            last_folder += "/"

            if not folder[i].startswith(last_folder):
                Result.append(folder[i])
        return Result
    

