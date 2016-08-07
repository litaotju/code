#include <iostream>
using namespace std;

int maxBottles(int n){
    if( n <=1 )
        return 0;
    if(n==2)
        return 1;
    return n/3+ maxBottles(n/3 + n%3);
}

int main(){
    int N;
    while(cin>>N && N >0){
        cout<< maxBottles(N)<<endl;
    }
    return 0;
}