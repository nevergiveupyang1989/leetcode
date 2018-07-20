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
        if root is None:
            return 0

        res = [root.val]

        self.help(root, res)

        return res 
    
    def help(self, root, result):
        '''
        res[0]采用列表，是值引用，每一层递归都会改变此值,表示最大的值
        '''
        if root is None:
            return 0

        left = self.help(root.left, result)
        right = self.help(root.right, result)

        result[0] = max(result[0], max(left,0)+max(right,0)+root.val)

        return max(root.val,root.val+left, root.val+right)

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




