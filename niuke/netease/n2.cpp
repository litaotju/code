#include <iostream> 
#include <cmath>
using namespace std;


int main(){
    long long h;
    cin>>h;
    long long x = floor((pow(1+4*h, 0.5)-1.0)/2.0);
    cout<<x<<endl;
}