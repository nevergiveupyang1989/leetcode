#---*--- coding:utf-8   ---*---

class Node(object):
    def __init__(self,val):
        self.left = None
        self.right = None
        self.val = val

class Tree():
    def createTree(self, preOrder, midOrder):
        if preOrder == [] or midOrder == []:
            return None

        val = preOrder.pop(0)
        idx = midOrder.index(val)

        left = midOrder[:idx]
        right = midOrder[idx+1:]
        curNode = Node(val)
        curNode.left = self.createTree(preOrder,left)
        curNode.right = self.createTree(preOrder,right)

        return curNode

preOrder = [2,3,4]
midOrder = [3,2,4]
tree = Tree()
curNode = tree.createTree(preOrder, midOrder)

assert curNode.val == 2
assert curNode.left.val == 3 
assert curNode.right.val == 4
