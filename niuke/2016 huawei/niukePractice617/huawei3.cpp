#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int hex2dec(string hex){
    assert(hex.size()>=3 && hex[0]=='0' &&(hex[1]=='X'|| hex[1]=='x'));
    int result = 0;
    for(int i =2; i< hex.size(); i++){
        if( hex[i]>='0' && hex[i] <='9'){
            result = result*16 + static_cast<int>(hex[i]-'0');
        }else if(hex[i] >='A' && hex[i]<='F'){
            result = result*16 + static_cast<int>(hex[i]-'A')+10;
        }else if(hex[i] >='a' && hex[i]<='f'){
             result = result*16 + static_cast<int>(hex[i]-'a')+10;
        }else{
            cerr<<"This is not a legal hex";
            continue;
        }
    }
    return result;
}

int main(){
    string hex;
    while(cin>>hex){
        cout<<hex2dec(hex)<<endl;
    }
}