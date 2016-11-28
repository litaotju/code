# -*- coding:utf-8 -*- #
def insert_sort(A):
    '''插入排序,从小到大排序
    '''
    for j in range(1,len(A)):
        key = A[j]
        i = j-1
        while( i>=0 and A[i]>key ):
            A[i+1] = A[i]
            i -= 1
        A[i+1] = key
    return A
def insort_sort2(A):
    '''插入排序,从大到小排序
    '''
    for j in range(1,len(A)):
        key = A[j] #当前待排序元素
        i = j-1
        while( i>= 0 and A[i]<key):
            A[i+1] = A[i]
            i -= 1
        A[i+1] = key
    return A
    
if __name__ == '__main__':
    A = [18,9,25,6,37,13,208]
    B = [6, 9, 13, 18,25, 37, 208]
    assert insert_sort(A) == B
    print insort_sort2(A)