#!usr/local/bin/python
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None 
        self.right = None 

class Solution(object):
    def __init__(self):
        self.res = []

    def sumNumbers(self, root):
        if root is None:
            return 0
        
        num = 0
        return self.dfs(root, num)

    def dfs(self, root, num):
        if root is None:
            return 0

        num = num*10 + root.val

        if root.left is None and root.right is None:
            return num
        
        return self.dfs(root.left, num) + self.dfs(root.right, num)


if __name__ == '__main__':
    s = Solution()
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)

    node1.left = node2 
    node1.right = node3 

    num = s.sumNumbers(node1)

    print num




