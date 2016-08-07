#include <vector>
#include <iostream>
using namespace std;

int main(){
    
    const int MAX =1001;
    int N;
    while(cin>>N && N>0){
        vector<int> array(MAX, 0);
        int num;
        for(int i=0;i<N; i++){
            cin>>num;
        	array[num]++;
        }
        for(int i=1; i<MAX; i++){
            if(array[i]>0)
                cout<<i<<endl;
        }
    }
}