# -*- coding:utf-8 -*- #
def bisearch(A, x):
    '''二分查找法,在A中查找元素x
    '''
    p = -1
    l = 0
    u = len(A)-1
    while(l <= u): #有一个Bug,当len(A)=1时,根本进行查找
        # mustbe [l,u]
        m = (l+u)/2
        if A[m] == x:
            p = m
            break
        elif A[m] > x:
            #在左边, mustbe [l, m-1]
            u = m-1
        else: # A[m] < x , mustbe [m+1, u]
            l = m+1
    return p
        
if __name__ == "__main__":
    A = [1,2,3,5,6,8]
    p = bisearch(A,3)
    print A[p]
    p = bisearch(A, 10)
    print p
    B = [1]
    p = bisearch(B, 1)
    print p