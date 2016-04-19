#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

#define PI 3.1415927

int main(int agrc, char * argv[]){
    double r;
    while(cin>>r){
        printf( "%.3f\n", (4.0/3.0)*PI*pow(r,3) );
    }
    
}