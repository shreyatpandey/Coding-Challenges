class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class MaximumSumPath:
    path = []
    sum = float('-inf')

    def maxPathSum(self, root):
        if root is None:
            return []

        self.sum = float('-inf')
        self.maxPathSumUtil(root)
        return self.path

    def maxPathSumUtil(self, root):
        if root is None:
            return []

        currRoot = []
        leftTree = self.maxPathSumUtil(root.left)

        leftTreeSum = max(0, sum(leftTree))
        currSum = leftTreeSum
        if leftTreeSum > 0:
            currRoot.extend(leftTree)

        currSum += root.val
        currRoot.append(root.val)

        rightTree = self.maxPathSumUtil(root.right)
        rightTreeSum = max(0, sum(rightTree))
        currSum += rightTreeSum
        if rightTreeSum > 0:
            currRoot.extend(rightTree)

        if currSum > self.sum:
            self.path = []
            self.path.extend(currRoot)
            self.sum = currSum

        if leftTreeSum > rightTreeSum:
            for item in rightTree:
                currRoot.remove(item)
        elif rightTreeSum > leftTreeSum:
            for item in leftTree:
                currRoot.remove(item)

        return currRoot

if __name__ == "__main__":
    root = TreeNode(-1)
    root.left = TreeNode(-2)
    root.left.left = TreeNode(3)
    root.left.left.left = TreeNode(100)
    root.left.left.right = TreeNode(101)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(7)

    print(" ".join(map(str, MaximumSumPath().maxPathSum(root))))
