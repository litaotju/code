#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    
    int ascii[128];
    memset(ascii, 0, sizeof(ascii));
    
    for(auto e: s)
        ascii[e]++;
    
    int cnt= 0;
    for(int i=0; i<128; i++){
        if(ascii[i]!=0)
            cnt++;
    }
        
    cout<<cnt;
}
