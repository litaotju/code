class Queue:


    def __init__(self,length):
        self.length = length
        self.entity = [None]*length
        self.head = 0
        self.tail = 0

    def enqueue(self,x):
        if (self.head == 0 and self.tail == self.length) or \
            (self.head == self.tail+1):
            raise Exception ,"Overflow, Queue is full ,and enqueue failed"
        self.entity[self.tail] = x
        if self.tail == self.length:
            self.tail = 1
        else:
            self.tail += 1

    def dequeue(self):
        if self.head == self.tail:
            raise Exception ,"Under flow, deque from empty queue"
        x = self.entity[self.head]
        self.entity[self.head] =None 
        if self.head == self.length:
            self.head =1
        else:
            self.head += 1
        return x
    
    def is_empty(self):
        if self.head == self.tail:
            return True
        else:
            return False

if __name__ == "__main__":
    ''' test for Queue class '''
    q1 = Queue(5)
    print q1.length

    for i in range(5):
        q1.enqueue(i)
    for i in range(3):
        print q1.dequeue()
    print "head %d :" %q1.head
    print "tail %d :" %q1.tail
    print "q entity:%s" % q1.entity
    
    
        
