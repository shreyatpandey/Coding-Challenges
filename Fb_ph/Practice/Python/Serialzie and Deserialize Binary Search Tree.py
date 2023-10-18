# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
'''
Complexity
Tc:- O(n)
Sc:- O(n)
where n is the number of nodes
'''
class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
    
        def constructString(root,listVal):
            if root == None:
                listVal.append(str('#,'))
                return 
            listVal.append(str(root.val)+",")
            constructString(root.left,listVal)
            constructString(root.right,listVal)
            

        listVal = []
        result = constructString(root,listVal)
        stringResult = ""
        for char in listVal:
            stringResult += char
        return stringResult
        

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        Queue = data.split(',')
        del Queue[-1] #deleting for last extra space
        '''
        Biggest challenge :- construct BST from post Order Traversal
        '''
        def BST(Queue):
            if Queue[0] == '#':
                del Queue[0]
                return None
            else:
                root = TreeNode(int(Queue[0]))
                del Queue[0]
                root.left = BST(Queue)
                root.right = BST(Queue)
                
                return root
            
        return BST(Queue)

'''
Approach-2:- Using bytes
Tc:- O(N)
Sc:- O(N)
'''
class Codec:
    def postorder(self, root):
        return self.postorder(root.left) + self.postorder(root.right) + [root.val] if root else []
        
    def int_to_str(self, x):
        """
        Encodes integer to bytes string
        """
        bytes = [chr(x >> (i * 8) & 0xff) for i in range(4)]
        bytes.reverse()
        bytes_str = ''.join(bytes)
        return bytes_str
        
    def serialize(self, root):
        """
        Encodes a tree to a single string.
        """
        lst = [self.int_to_str(x) for x in self.postorder(root)]
        return ''.join(map(str, lst))
    
    def str_to_int(self, bytes_str):
        """
        Decodes bytes string to integer.
        """
        result = 0
        for ch in bytes_str:
            result = result * 256 + ord(ch)
        return result
        
    def deserialize(self, data):
        """
        Decodes your encoded data to tree.
        """
        def helper(lower = float('-inf'), upper = float('inf')):
            if not data or data[-1] < lower or data[-1] > upper:
                return None
            
            val = data.pop()
            root = TreeNode(val)
            root.right = helper(val, upper)
            root.left = helper(lower, val)
            return root
        
        n = len(data)
        # split data string into chunks of 4 bytes
        # and convert each chunk to int
        data = [self.str_to_int(data[4 * i : 4 * i + 4]) for i in range(n // 4)]
        return helper() 
