#include <iostream>
using namespace std;

int drinks(int n){
    if( n <= 1)
        return 0;
    if( n == 2)
        return 1;
    int canDrink = n/3;
    return canDrink + drinks( n%3 + canDrink);
}

int main(){
    int N;
    while(cin>>N && N >0){
        cout<< drinks(N)<<endl;
    }
}