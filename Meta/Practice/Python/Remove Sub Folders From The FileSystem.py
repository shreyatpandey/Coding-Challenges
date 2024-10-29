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
    

'''
Approach - 2 : Trie
Let N be the length of the folder and L maximum length of the folder path
TC :- O(N*L)
SC :- O(N*L)
Max space is taken by Trie Node as we need to construct Node for 
each iteration when the folder name is not present
'''
class Solution(object):
    class Trie:
        def __init__(self):
            self.child = {}
            self.is_end = False
    
    def __init__(self):
        self.root = self.Trie()
    
    def removeSubfolders(self, folder):
        """
        :type folder: List[str]
        :rtype: List[str]
        """
        for path in folder:
            current_folder = self.root
            list_folder = path.split("/")
        
            for folder_name in list_folder:
                if folder_name == "":
                    continue

                if folder_name not in current_folder.child:
                    current_folder.child[folder_name] = self.Trie()
                current_folder.child = current_folder.child[folder_name]
        current_folder.is_end = True

        Result = []
        for path in folder:
            current_node = self.root
            folders = path.split("/")
            is_subfolder = False

            for i,folder_name in enumerate(folders):
                if folder_name == "":
                    continue
                next_node = current_node.child[folder_name]

                if next_node.is_end and i != len(folders) - 1:
                    is_subfolder = True
                current_node = next_node
            
            if not is_subfolder:
                Result.append(path)
        
        return Result
    