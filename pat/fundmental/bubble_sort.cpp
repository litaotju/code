/*将NN个整数按从小到大排序的冒泡排序法是这样工作的：从头到尾比较相邻两个元素，如果前面的元素大于其紧随的后面元素，则交换它们。通过一遍扫描，则最后一个元素必定是最大的元素。
然后用同样的方法对前N-1N−1个元素进行第二遍扫描。依此类推，最后只需处理两个元素，就完成了对NN个数的排序。

本题要求对任意给定的KK（<N<N），输出扫描完第KK遍后的中间结果数列。

输入格式：

输入在第1行中给出N和K（1\le K<N\le 1001≤K<N≤100），在第2行中给出NN个待排序的整数，数字间以空格分隔。

输出格式：

在一行中输出冒泡排序法扫描完第KK遍后的中间结果数列，数字间以空格分隔，但末尾不得有多余空格。

输入样例：

6 2
2 3 5 1 6 4
输出样例：

2 1 3 4 5 6

*/
//bubble sort
#include <iostream>
using namespace std;
void bulle_sort(int * data, int N, int K){
    for(int i=0; i<K; ++i){
        for(int j=i; j<N-1;++j){
            if(data[j]>data[j+1]){
                int temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
            }
        }
    }
}


int main(){
    int N, K;
    while(cin>>N>>K){
        int *data = new int[N];
        for(int i =0; i<N; ++i){
            cin>>data[i];
        }
        bulle_sort(data, N, K);
        for(int i =0; i<N; ++i){
            cout<<data[i];
            if(i<N-1)
                cout<<" ";
        }
        cout<<endl;
    }
}