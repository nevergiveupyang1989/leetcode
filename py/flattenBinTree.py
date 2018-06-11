#! usr/local/bin/python

class TreeNode:
    def __init__(self,val):
        self.val = val 
        self.left = None 
        self.right = None 

class Solution():
    def __init__(self):
        self.res = []
    
    def preOrder(self, root):
        if root is None:
            return 
        self.res.append(root)
        self.preOrder(root.left)
        self.preOrder(root.right)

    def flatten(self,root):
        if res == []:
            return None 
        
        root.left = None 
        root.right = None 
        
        curNode = root 
        while self.res != []:
            curNode.right = self.pop(-1)
            curNode.left = None 

        curNode.left = None 
        curNode.right = None 
            

