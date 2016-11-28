#include <iostream>
using namespace std;

int main(){
    int N;
 	while(cin>>N){
        double x = N, sum = N;
        for(int i=1; i<5; i++){
            sum += x;
            x /= 2;
        }
        x /= 2;
        cout<<sum<<endl;
        cout<<x<<endl;
    }   
}