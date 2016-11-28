class Bilink:
    '''双向链表,head.left == None, 尾部的元素.right ==None  
    '''
    def __init__(self):
        self.head = LinkPoint()# insert an empty point
    def search(self, value):
        '列表搜索操作'
        x = self.head
        while(x and (x.value is not value)):
            x = x.right
        return x
        
    def insert(self, x):
        '列表头插入x'
        x.right = self.head
        if self.head: #如果列表头不为空
           self.head.left = x #将X赋值给原先头的左
        self.head = x #列表头为x
        x.left = None #x的左为None
   
    def delete(self, px):
        if px.left and px.right:
            px.left.right = px.right.left
        elif px.left: #px is tail
            px.left.right = None
        else:# px is head of 
            self.head = px.right
            
class LinkPoint:
    def __init__(self, value= None):
        self.left = None
        self.right = None
        self.value = value
        
if __name__=="__main__":
    a = Bilink()
    a.insert(LinkPoint("nihao"))
    print a.head
    print a.search("nihao")
             
    
            
        
    
