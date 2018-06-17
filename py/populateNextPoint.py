#! usr/local/bin/python
class TreeLinkNode:
    def __init__(self, val):
        self.val = val
        self.left = None 
        self.right = None 
        self.next = None 

class Solution:
    def connect(self, root):
        if not root:
            return None 
       
        if not root.left and not root.right:
            return 

        root.left.next = root.right 

        self.connect(root.left)
        self.connect(root.right)
        self.connect_left_right(root.left, root.right)
        
        return root 

    def connect_left_right(self, left, right):
        if not left and not right:
            return 
        left.next = right 

        self.connect_left_right(left.right, right.left)

import unittest

class TestSolution(unittest.TestCase):
    def setUp(self):
        s = Solution()
        self.func = s.connect 

    def tearDown(self):
        del self.func  

    def testNoneNode(self):
        curNode = None 
        root = self.func(curNode)    
        self.assertEquals(root, None) 

    def testNotNoneNode(self):
        curNode = TreeLinkNode(1)
        curNode.left = TreeLinkNode(2)
        curNode.right = TreeLinkNode(3)

        root = self.func(curNode)
        self.assertEquals(root.left.next, curNode.right) 
if __name__ =='__main__':
    unittest.main()

        
        
