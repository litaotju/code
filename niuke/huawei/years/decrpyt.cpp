#include<iostream>
#include <string>
using namespace std;

string decrpyt(const string & passwd){
    string realPasswd;
    for(auto c: passwd){
        if( c>='A' && c<='Z'){
            c = 'a'+ c-'A';
            c = (c=='z') ? 'a': c+1;
        }else if( c>='a' && c<='z') {
            if( c <= 'o' ){
                c = '2' + (c-'a')/3;
            }else if( c<= 's'){
                c = '7';
            }else if(c<='v'){
                c ='8';
            }else{
                c = '9';
            }
        }
        realPasswd.push_back(c);
    }
    return realPasswd;
}

int main(){
    string s;
    while(getline(cin, s)){
        cout<<decrpyt(s)<<endl;
    }
}