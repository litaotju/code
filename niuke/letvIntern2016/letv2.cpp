#include <iostream>
#include <cmath>
using namespace std;

int numberOfArrange(int A, int B){
    //assert 1<= A,B<=2,000,000,000 and A<=B
    int lowerBound = static_cast<int>( ceil( double(A)/0.95));
    int higherBound = min(static_cast<int>(floor(double(A)/0.90)), B);
    if(lowerBound > higherBound)
        return 0;
    //返回 lowerBound 和 higherBound之间被5整除的数的个数
    int cnt = 0;
    int i;
    for(i = lowerBound; i<=higherBound; i++){
        if(i%5 ==0)
            break;
    }
    int j;
    for(j=higherBound; i>=lowerBound; j--){
        if(j%5==0)
            break;
    }
    return (j-i)/5+1;
}


int main(){
    int A, B;
    while(cin>>A>>B){
        cout<<numberOfArrange(A,B)<<endl;
    }
}   