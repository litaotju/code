# -*- coding:utf-8 -*-

# 2叉堆的基本性质:
#

def parent(i):
    return (i+1)/2

def left(i):
    return 2*(i+1)

def right(i):
    return 2*(i+1)+1

def max_heapify(A, i, heapsize):    
    l = left(i)
    r = right(i)
    if l <=  heapsize and A[l-1] > A[i]:
        largest = l-1
    else:
        largest = i
    if r <= heapsize and A[r-1] > A[largest]:
        largest = r - 1

    if largest != i:
        A[i], A[largest] = A[largest], A[i]
        max_heapify(A, largest, heapsize)

def build_max_heap(A):
    for  i in range(len(A)/2-1, -1, -1):
        max_heapify(A, i, len(A))
        
def heap_sort(A):
    build_max_heap(A)
    heapsize = len(A)
    for i in range(len(A), 0, -1):
        A[0], A[i-1] = A[i-1], A[0]
        heapsize -= 1
        max_heapify(A, 0, heapsize)
    return A
        
#A = list(range(7))
#A = [5, 3, 17, 10, 84, 19, 6, 22, 9]
A  = list(range(100, 0, -1))

print build_max_heap(A)
print heap_sort(A)


