# -*- coding:utf-8 -*- #

#反转单链表
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        ## This is wrong answer
        # reverse = None
        # while(head):
        #     tmp = head
        #     tmp.nexter = reverse
        #     head = head.nexter
        #     reverse = tmp
        # return reverse
        reverse = None
        while(head):
            temp = head
            head = head.nexter
            temp.nexter = reverse
            reverse = temp
        return reverse
### 单链表       
class Linklist:
    def __init__(self):
        self.head =None
        
    def insert(self, Linker):
        '''在最前端插入一个Linker'''
        Linker.nexter = self.head    
        self.head = Linker
        
class Linker:
    def __init__(self, val):
        self.val = val
        self.nexter = None
## 给链表头,打印整个链表     
def printlist(head):
    p =head
    while(p):
        print p.val
        p = p.nexter
if __name__=='__main__':
    l = Linklist()
    l.insert(Linker('a'))
    l.insert(Linker('b'))
    head = Linker('c')
    l.insert(head)
    printlist(head)
    s = Solution()
    head = s.reverseList(l.head)
    printlist(head)