class TreeNode:
    '''
    lFlag 值为0 表示存在左子树，不存在前节点，反之表示存在前节点
    rFlag 意义与上相同
    '''
    def __init__(self, left=None,lFlag=0, right=None,rFlag=0, data = '#'):
        self.left = left
        self.right = right
        self.lFlag = lFlag
        self.rFlag = rFlag
        self.data = data
        self.preNode = None

class ThreadedBinaryTree:
    def __init__(self):
        self.baseNode = self.createBinaryTree() 
    
    def getBaseNode(self):
        return self.baseNode

    def createBinaryTree(self):
        val = raw_input("input the data:")
        
        if(val=='#'):
            pNode = None

        else:
            pNode = TreeNode(data=val)
            pNode.left = self.createBinaryTree()
            pNode.right = self.createBinaryTree()
        
        return pNode

    def CreateThreadTree(self):
        '''
        前序创建二叉树
        '''
        root = TreeNode()
        self.preNode = root

        if self.baseNode is None:
            return

        root.left = self.baseNode
        root.right = self.baseNode
        self.threadedTree(self.baseNode)

    def threadedTree(self, presentNode):
        if presentNode is not None:
            self.threadedTree(presentNode.left)

            if presentNode.left is None:
                presentNode.lFlag = 1
                presentNode.left = self.preNode
            else:
                presentNode.lFlag = 0

            if self.preNode.right is None:
                self.preNode.rFlag = 1
                self.preNode.right = presentNode
            else:
                self.preNode.rFlag = 0
            
            self.preNode = presentNode
            
            self.threadedTree(presentNode.right)

if __name__ == '__main__':
    threadedTree = ThreadedBinaryTree()
    threadedTree.CreateThreadTree()
    baseNode = threadedTree.getBaseNode() 
