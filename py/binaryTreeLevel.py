#!/usr/local/bin/python

class TreeNode():
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None

class Solution():
    def __init__(self):
        self.res=[]

    def levelOrderBottom(self,root):
        res, queue = [], [root]

        while queue:
            res.append([node.val for node in queue if node])
            queue = [child for node in queue if node for child in (node.left,
                node.right)]

        return res[-2::-1]

if __name__ == '__main__':
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)

    node1.left = node2
    node1.right = node3

    s = Solution()
    res = s.levelOrderBottom(node1)

    print res



