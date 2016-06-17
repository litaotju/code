#include <iostream>
#include <cstring>
using namespace std;

const int M = 1000;

void sortAndOutput(int *inputValue, int N){
    int *sortedData = new int[M];
    memset(sortedData, 0, M*sizeof(int));
    for(int i=0; i<N; ++i){
        sortedData[inputValue[i]-1] = +1;
    }
    
    for(int i = 0; i<M; i++){
        if(sortedData[i]!=0)
            cout<<i+1<<endl;
    }
    delete []sortedData;
}


int main(){
    int N;
    while(cin>>N && N>0){
        int *inputValue = new int[N];
        for(int i =0; i<N;i ++){
            cin>> inputValue[i];
        }
        sortAndOutput(inputValue, N);
        delete [] inputValue;
    }
}