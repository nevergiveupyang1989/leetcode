#! usr/local/bin/python
import unittest
import copy 

class TreeNode:
    def __init__(self,val):
        self.val = val 
        self.left = None 
        self.right = None 


class Solution:
    def __init__(self):
        self.res = []
        self.tmp = []

    def pathSum(self, root, num):
        if root is None:
            return 0
        if not root.left and not root.right:
            if root.val == num:
                self.tmp.append(root.val)
                self.res.append(copy.copy(self.tmp))

                return True 
            else:
                self.tmp = []
                return False 
        else: 
            self.tmp.append(root.val)
        
        left = False 
        right = False 

        if root.left:
            left = self.pathSum(root.left, num-root.val)
            
            if left:
                self.tmp.pop()

        if root.right:
            right = self.pathSum(root.right, num-root.val)
            
        return left or right 

class TestpathSum(unittest.TestCase):
    def setUp(self):
        self.solution = Solution()
        self.testfunc = self.solution.pathSum  
        
    def tearDown(self):
        del self.testfunc 

    def testNoneNode(self):
        curNode = None
        num = 1
        self.testfunc(curNode, num)
        res = self.solution.res 
        self.assertListEqual(res,[])

    def testExistOnePath(self):
        curNode = TreeNode(0)
        curNode.left = TreeNode(1)
        curNode.right = TreeNode(2)
        self.testfunc(curNode, 1)
        res = self.solution.res 
        self.assertListEqual(res,[[0,1]])

    def testExistMulPath(self):
        curNode = TreeNode(0)
        curNode.left = TreeNode(1)
        curNode.right = TreeNode(1)
        self.testfunc(curNode, 1)
        res = self.solution.res 
        self.assertListEqual(res, [[0,1],[0,1]])

if __name__ == '__main__':
    unittest.main()
