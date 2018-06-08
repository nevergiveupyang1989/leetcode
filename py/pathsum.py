#! usr/local/bin/python
import unittest

class TreeNode:
    def __init__(self,val):
        self.val = val 
        self.left = None 
        self.right = None 

class Solution:
    def hasPathSum(self, root, sum):
        if root is None:
            return False 

        if not root.left and not root.right:
            if sum-root.val == 0:
                return True 
            else:
                return False 

        left = False 
        right = False 

        if root.left:
            left = self.hasPathSum(root.left, sum-root.val)
        if root.right:
            right = self.hasPathSum(root.right, sum-root.val)

        return left or right 

class TestPathSum(unittest.TestCase):
    def setUp(self):
        pass 

    def tearDown(self):
        pass 


if __name__ == '__main__':
    curNode = TreeNode(0)
    curNode.left = TreeNode(1)
    curNode.right = TreeNode(2)

    res = Solution().hasPathSum(curNode, 2)
    print res 

