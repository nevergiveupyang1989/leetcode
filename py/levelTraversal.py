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
        self.res=[[]]
        self.que=[]
    
    def queIsEmpty(self):
        if len(self.que) == 1 and self.que[0] == '*':
            return True
        return False

    def solution(self, root):
        topNode = None
        idle = '*'

        if root is None:
            return

        self.que.append(root)
        self.que.append(idle)

        while(self.queIsEmpty() is not True):
            topNode = self.que.pop(0)

            if topNode == '*' :
                self.res.append([])
            else:
                self.res[-1].append(topNode.val)
            
            if topNode != '*' and topNode.left is not None:
                self.que.append(topNode.left)
            
            if topNode != '*' and topNode.right is not None:
                self.que.append(topNode.right)
            
            if self.que[-1] != '*':
                self.que.append(idle)

        return self.res


if __name__ == "__main__":
    rootNode = createTree()
    traversal = LevelTraversal()
    res = traversal.solution(rootNode)

    print res
