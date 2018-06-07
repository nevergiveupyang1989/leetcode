#! /usr/local/bin/python
#--*---:coding:utf-8---*---

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


if __name__ == '__main__':
    curNode = TreeNode(0)

    solution = Solution()
    res = solution.minDepth(curNode)
    print res
