#include <iostream>
using namespace std;

int count1(int n){
    int cnt=0;
    while(n){
        cnt++;
        n = n&(n-1);
    }
    return cnt;
}

int main(){
    int N;
    cin>>N;
    cout<<count1(N)<<endl;
    return 0;
}