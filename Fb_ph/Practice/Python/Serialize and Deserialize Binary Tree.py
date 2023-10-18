'''
Complexity
Time complexity: O(n)
Space complexity: O(n)
'''
'''
DFS
'''
class Codec:
    def serialize(self, root):
        if not root: return "#"
        return str(root.val) + "," + self.serialize(root.left) + "," + self.serialize(root.right)

    def deserialize(self, data):
        def deserialize_helper(queue):
            val = queue.popleft()
            if val == "#":
                return None
            node = TreeNode(int(val))
            node.left = deserialize_helper(queue)
            node.right = deserialize_helper(queue)
            return node
        
        queue = deque(data.split(","))
        return deserialize_helper(queue)
'''
BFS
'''
class Codec:
    def serialize(self, root):
        if not root:
            return ""
        queue = [root]
        result = []
        while queue:
            node = queue.pop(0)
            if node:
                result.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append("#")
        return ",".join(result)

    def deserialize(self, data):
        if not data:
            return None
        values = data.split(",")
        root = TreeNode(int(values[0]))
        queue = [root]
        i = 1
        while queue:
            node = queue.pop(0)
            if values[i] != "#":
                left = TreeNode(int(values[i]))
                node.left = left
                queue.append(left)
            i += 1
            if values[i] != "#":
                right = TreeNode(int(values[i]))
                node.right = right
                queue.append(right)
            i += 1
        return root
