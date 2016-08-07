#include <iostream>
using namespace std;

int main(){
    
    long input;
    cin>>input;
    while(input!=1){
       	for(int i=2; i<=input; i++){
            if(input%i == 0){
            	input /=i;
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}