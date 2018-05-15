class Tree():
    def __init__(self,val,left=None,right=None):
        self.val = val
        self.left = left
        self.right = right
    
def createTree():
    curNode = None
    val = raw_input("Please input the val:")
    
    if val == '#':
        curNode = None
    
    else: 
        curNode = Tree(val)
        curNode.left = createTree()
        curNode.right = createTree()

    return curNode

class Solution():
    def maxDeep(self,root):
        curNode = root
        if root is None:
            maxDepth = 0
        else:
            maxDepth = max(self.maxDeep(curNode.left)+1, self.maxDeep(curNode.right)+1)

        return maxDepth

if __name__ == '__main__':
    root = createTree()
    solution = Solution()
    print solution.maxDeep(root)
