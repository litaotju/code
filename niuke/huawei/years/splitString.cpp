#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        int i=0;
        while( i< s.size() && i+8<s.size()){
            cout<< s.substr(i, 8)<<endl;
            i += 8;
        }
        if(i < s.size()){
            cout<< s.substr(i, s.size()-i);
            cout<< string(8+i-s.size(), '0');
            cout<<endl;
        }
    }
    return 0;
}