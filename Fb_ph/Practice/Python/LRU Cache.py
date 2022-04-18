'''
The functions get and put must each run in O(1) average time complexity.
Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
'''
'''
Time-Complexity
TC:- O(1) for get and put operation
'''
class Node(object):
    def __init__(self,Key,Val):
        self.key = Key
        self.val = Val
        self.next = None
        self.prev = None
        
class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.LRUCache = {}
        self.Capacity = capacity
        self.left = Node(-1,-1)
        self.right = Node(-1,-1)
        self.left.next = self.right
        self.right.prev = self.left
    
    def remove(self,RemoveNode):
        nextNode = RemoveNode.next
        previousNode = RemoveNode.prev
        previousNode.next = nextNode
        nextNode.prev = previousNode
        
    
    def add(self,key,val):
        newNode = Node(key,val)
        Previous = self.right.prev
        Previous.next = newNode
        newNode.prev = Previous
        self.right.prev = newNode
        newNode.next = self.right
        self.LRUCache[key] = newNode
    
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.LRUCache:
            return -1
        retVal = self.LRUCache[key].val
        self.remove(self.LRUCache[key])
        self.add(key,retVal)
        return retVal
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: None
        """
       
        if key in self.LRUCache: #O(1)
            self.remove(self.LRUCache[key])
        
        self.add(key,value)
        
        if len(self.LRUCache) > self.Capacity: #question should I delete the node completely
            LRUNode = self.left.next
            self.remove(LRUNode)
            del self.LRUCache[LRUNode.key]
        
        
                
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
