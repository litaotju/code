#include <iostream>

using namespace std;

int computeMaxSumArray(int array[], int K){
    int curSum = 0;
    int index =0;
    int greatestSum = 0X80000000;
    
    while(index < K){
        if(curSum <= 0){
            curSum = array[index];
        }else{
            curSum += array[index];
        }
        if(curSum > greatestSum){
            greatestSum = curSum;
        }
        index++;
    }
    return greatestSum;
}


int main(){
    int start, end;
    int K;
    cin>>K;
    int *array = new int[K];
    for(int i=0; i<K; i++){
        cin>> array[i];
    }
    cout<<computeMaxSumArray(array, K);
}