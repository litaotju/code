#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double num;
    cin>>num;
    double flor = floor(num);
    if( num - flor >= 0.5 )
        cout<< static_cast<int>(flor)+1;
    else
        cout<< static_cast<int>(flor);
    return 0;
}