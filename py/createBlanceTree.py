#! /usr/local/bin/python

class TreeNode:
    def __init__(self,val):
        self.val = val
        self.left = None
        self.right = None


class Solution:
    def sortedArray2BST(self,num):
        if len(num) == 0:
            return None

        mid = len(num)/2
        curNode = TreeNode(num[mid])
        curNode.left = self.sortedArray2BST(num[:mid])
        curNode.right = self.sortedArray2BST(num[mid+1:])

        return curNode

if __name__ == '__main__':
    solution = Solution()
    num = [0,1,2,3]
    curNode = solution.sortedArray2BST(num)

    
