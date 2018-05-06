class Tree(object):
    def __init__(self, val, left=None, right=None):
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

class LevelTraversal(object):
    def __init__(self):
        self.res=[]
        self.que=[]
    
    def queIsEmpty(self):
        if len(self.que) == 0:
            return True
        return False

    def solution(self, root):
        topNode = None

        if root is None:
            return

        self.que.append(root)

        while(self.queIsEmpty() is not True):
            topNode = self.que.pop()
            self.res.append(topNode.val)

            if topNode.right is not None:
                self.que.append(topNode.right)

            if topNode.left is not None:
                self.que.append(topNode.left)

        return self.res


if __name__ == "__main__":
    rootNode = createTree()
    traversal = LevelTraversal()
    res = traversal.solution(rootNode)

    print res
