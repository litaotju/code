# -*- coding:utf-8 -*-
def bubble_sort(A):
	'''冒泡排序
	'''
	for i in range(len(A)):
		for j in range(len(A),i,-1): #len(A)- i+1
			if A[j] < A[j-1]:
				A[j], A[j-1] = A[j-1], A[j]

import unittest
class BubbleTest(unittest.TestCase):
	'''
	'''
	def setup(self):
		print 'setUp for Test'
	
	def teardown(self):
		print 'tearDown for Test'
	
	def testRandom(self):
		A = [10, 9, 13, 57, 8]
		B = [8, 9 ,10 , 13, 57]
		bubble_sort(A)
		print A
		self.assertEqual(A, B, 'test Random test Failed')

if __name__ == '__main__':
	unittest.main()
	
			