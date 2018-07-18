#! usr/local/bin/python

class TreeNode(object):
    def __init__(self, val):
        self.val = val
        self.left = None 
        self.right = None 

class Solution(object):
    def __init__(self):
        self.max = 0
        self.tmp = 0

    def maxPathSum(self, root):
        tmp = 0

        if root is None:
            return 
        
        if root.val > 0:
            self.tmp += root.val
        else:
            tmp = self.tmp 
            self.tmp = 0
        
        self.max = max(self.max, max(tmp, self.tmp))
        self.maxPathSum(root.left)
        
        if root.val < 0:
            self.tmp = 0

        self.maxPathSum(root.right)

        return self.max 


if __name__ == '__main__':
    node1 = TreeNode(-10)
    node2 = TreeNode(9)
    node3 = TreeNode(20)
    node4 = TreeNode(15)
    node5 = TreeNode(7)

    node1.left = node2 
    node1.right = node3 
    node3.left = node4 
    node3.right = node5

    s = Solution()

    max_ = s.maxPathSum(node1)

    print max_




