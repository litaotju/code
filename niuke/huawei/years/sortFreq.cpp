#include <map>
#include <iostream>
using namespace std;

int main(){
    int N;
    while(cin>>N && N>0){
        map<int, int> dict;
        int key, value;
        for(int i=0; i<N; i++){
            cin>>key>>value;
           	dict[key] += value;
        }
        for(auto &e: dict)
            cout<< e.first<<" "<<e.second<<endl;
    }
}