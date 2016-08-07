#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    char c;
    getline(cin, s);
    cin>>c;
    char C;
    int cnt  =0;
    if( c >='a' && c<='z')
        	C = c-'a'+'A';
    else if( c >='A' && c<='Z')
        	C = c-'A'+'a';
    else 
        C = c;
        
    for(int i=0; i<s.size(); i++){
    	if(s[i] == c|| s[i] ==C)
            cnt++;
    }
    cout<<cnt;
}