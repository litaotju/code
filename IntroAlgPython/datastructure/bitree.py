class Bitree:
    '二叉树类'
    def __init__(self, root = None):
        self.root = root
            
    def travel(self, root):
        # 深度优先遍历
        if root:
            print root.key
            self.travel(root.left)
            self.travel(root.right)
        else:
            return None
            
class Tnode:
    def __init__(self, key =None ):
         self.key = key
         self.parent = None
         self.left = None
         self.right = None

if __name__ == '__main__':
    nlist = [Tnode(i) for i in range(0,10) ]
    tr = Bitree(nlist[0])
    tr.travel(tr.root)
    nlist[0].left = nlist[1]
    nlist[0].right = nlist [2]
    nlist[1].left = nlist[8]
    nlist[1].right = nlist[9]
    nlist[8].left = nlist[5]
    tr.travel(tr.root)