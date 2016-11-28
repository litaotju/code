# -*- coding: utf-8 -*- #
class HashTable:
    '''哈希表类，在初始化的时候需要指定callable哈希函数和表的长度。
       使用chainng的方法来解决collision的问题
    '''
    def __init__(self, callablefunc, m): 
        self.h = callablefunc
        self.table = [None]*m #m个空链表
        self.m = m
    
    def insert(self, k): #插入关键字
        hashfunc = self.h
        addr = hashfunc(k)
        linkk = self.table[addr]
        if not linkk:    #位置为空
            linkk = Link()
        linkk.insert(Linker(k))
        self.table[addr] = linkk
    def show(self):
        for i in range(self.m):
            linki = self.table[i]
            if not linki:
                print "None"
            else:
                linki.show()
        
        
class Link:
    '''单链表，初始化时候不要任何参数。insert函数在链表头插入元素Linker对象val
    '''
    def __init__(self):
        self.head = Linker()
        self.head.succ = None
    
    def insert(self, val):
        pre_head = self.head
        val.succ =pre_head
        self.head = val
    
    def show(self):
        p = self.head
        print "Link:",
        while(p):
            print " "+str(p.val),
            p = p.succ
        print "."
        
class Linker:
    '''链表的元素数据结构
    '''
    def __init__(self, val=None):
        self.val = val
        self.succ = None
        
def hash1(k):
    assert type(k) ==int 
    return k % 9

def hash2(k):
    assert type(k) == str
    addr = 0 #
    addr = int(k)%100
    return addr
if __name__ == '__main__':
    
    hashtable1 = HashTable(hash1, 9)
    hashtable1.insert(10)
    hashtable1.insert(28)
    hashtable1.insert(16)
    hashtable1.show()
    
    hashtable2 = HashTable(hash2, 100)
    hashtable2.insert('1000')
    hashtable2.insert('12345')
    hashtable2.insert('12123')
    hashtable2.insert('23')
    hashtable2.show()
    