#! /usr/local/bin/python
#--*---:coding:utf-8---*---
import unittest

class TreeNode:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def minDepth(self, root):
        if root is None:
            return 0

        return min(self.minDepth(root.left)+1,self.minDepth(root.right)+1)


class TestMinDepth(unittest.TestCase):
    '''
    def test_init(self):
        self.solution = Solution().minDepth 
        print type(self.solution)
    '''

    def setUp(self):
        self.solution = Solution().minDepth  

    def tearDown(self):
        del self.solution 

    def test_nonenode(self):
        curNode = None 
        self.assertEquals(self.solution(curNode), 0)

    def test_justleft(self):
        curNode = TreeNode(0)
        curNode.left = TreeNode(1)
        curNode.left.left = TreeNode(2)

        self.assertEquals(self.solution(curNode), 1)

    def test_justright(self):
        curNode = TreeNode(0)
        curNode.right = TreeNode(1)
        curNode.right.right = TreeNode(2)

        self.assertEquals(self.solution(curNode),1)

    def test_blancenode(self):
        curNode = TreeNode(0)
        curNode.left = TreeNode(1)
        curNode.rigth = TreeNode(2)

        self.assertEquals(self.solution(curNode),2)
    
    def test_nonblancenode(self):
        curNode = TreeNode(0)
        curNode.left = TreeNode(1)
        curNode.right = TreeNode(2)
        curNode.left.left = TreeNode(3)

        self.assertEquals(self.solution(curNode), 2)
if __name__ == '__main__':
    unittest.main()
