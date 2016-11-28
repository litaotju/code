# -*- coding:utf-8 -*- #
def merge_sort(A, p, r):
    '''合并排序算法的实现
    '''
    assert p <= r
    if p < r:
        q = (p+r)/2 #不仅除法 还要取整数
        merge_sort(A, p, q)
        merge_sort(A, q+1 ,r)
        merge(A, p, q, r)
    # elif p == r:
        #什么也不做  
        
def merge(A, p, q, r):
    '''合并数组A[p:q] A[q+1:r]
    '''
    lf = [a for a in A[p:q+1] ]
    rt = [a for a in A[q+1:r+1] ]    
    lf.append(float('inf'))
    rt.append(float('inf'))
    i = 0
    j = 0
    for k in range(0, r+1-p):
        # 将两个数中大的数赋值给A[k]
        if lf[i] < rt[j]:
            A[p+k] = lf[i]
            i += 1
        else:
            A[p+k] = rt[j]
            j += 1
            
import unittest
class MergeSortTest(unittest.TestCase):
     
    def setUp(self):
        print "setUp MergeSortTest"
    
    def tearDown(self):
        print "TearDown MergeSortTest"
    
    def testEmpty(self):
        A = []
        B = []
        merge_sort(A, 0, 0 )
        self.assertEqual(A, B)
    
    def testOne(self):
        A = [1]
        B = [1]
        merge_sort(A, 0 , 0 )
        self.assertEqual( A, B)
    
    def testRandom(self):
        A = [19, 3, 67, 5, 19]
        B = [3, 5, 19, 19, 67]
        merge_sort(A, 0, 4)
        self.assertEqual(A, B, "test Random failed")
        
if __name__ == '__main__':
    unittest.main()
     
        