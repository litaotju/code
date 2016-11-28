#include <iostream>
using namespace std;
/*
C++ 二维数组的使用
*/
int main(int argc, char * argv[]){
    int M, N;
    while(cin>>M>>N){
        if(M==0 && N ==0)
            break;
        
        //创建
        int **array;
        array = new int*[M];
        for(int i=0; i< M; i++){
            array[i] = new int[N];
        }
        
        //使用
        for(int i=0; i< M; i++){
           for(int j=0; j<N; j++){
                cin>>array[i][j];
                cout<<array[i][j]<<" ";
            }
            cout<<endl;
        }
        
        //销毁
        for(int i=0; i<N; i++){
            delete [] array[i];
        }
        delete []array;
    }
}