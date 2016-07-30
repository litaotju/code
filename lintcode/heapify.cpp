#include <vector>
#include <iostream>
using namespace std;
/*
�ѻ�����һ��������һ����С��
*/

void print_v(const vector<int> &A){
	for(auto &v:A){
		cout <<v<<" ";
	}
    cout<<endl;
}

class Solution {
public:
    /**
     * @param A: Given an integer array
     * @return: void
     */
    void heapify(vector<int> &A) {
        // write your code here
        if(A.empty())
            return;
        for(int root = A.size()/2-1; root >=0; root--){
            heapify(A, root);
            //cout<<root<<endl;
            //print_v(A);
        }
    }
    
private:
    void heapify(vector<int> &A, int root){
        while(root<A.size()){
            int small = root;
            //����ӱȽ�С
            if( root*2+1 < A.size() && A[root]>A[root*2+1]){
                small = root*2 + 1;
            }
            //�Ҷ��ӱȽ�С
            if(root*2+2 < A.size() && A[small]>A[root*2+2]){
                small = root *2 +2;
            }
            //��С�ĸ���
            if(small != root){
                swap(A[small], A[root]);
                root = small;
            }else{
                break;
            }
        }
    }
    
private:
    void swap(int &a, int &b){
        int temp = a;
        a = b;
        b = temp;
    }
};


int main(){
vector<int> A {45,39,32,11};
Solution s;
s.heapify(A);
}