#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
    int N;
    while(cin>>N){
        int sum =0;
        for(int i=1; i<=N; i++)
            sum += i;
        cout<< sum <<endl<<endl;
    }
    return 0;
}

