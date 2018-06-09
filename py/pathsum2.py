#! usr/local/bin/python


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
            if root.val == sum:
                self.tmp.append(root.val)
                self.res.append(self.tmp)
            else:
                self.tmp = []
        
        self.tmp.append(root.val)

        if not root.left:
            self.pathSum(root.left, sum-root.val)

        if not root.right:
            self.pathSum(root.right, sum-root.val)

        return self.res 

if __name__ == '__main__':
    curNode = TreeNode(0)
    curNode.left = TreeNode(1)
    curNode.right  = TreeNode(2)

    res = Solution().pathSum(curNode, 1)
    
    print res

        
