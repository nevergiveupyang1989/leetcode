#---*---coding:utf-8---*---

class Node:
    def __init__(self,val):
        self.left = None
        self.right = None
        self.val = val

class Tree:
    def createTree(self, midOrder, postOrder):
        if midOrder == [] or postOrder == []:
            return None

        val = postOrder.pop()
        
        idx = midOrder.index(val)
        left = midOrder[:idx]
        right = midOrder[idx+1:]

        curNode = Node(val)
        curNode.right = self.createTree(right,postOrder)
        curNode.left = self.createTree(left,postOrder)
        
        return curNode

if __name__ == '__main__':
    midOrder = [3,2,4]
    postOrder = [3,4,2]

    tree = Tree()
    curNode = tree.createTree(midOrder,postOrder)
    print curNode.val, curNode.left.val, curNode.right.val


