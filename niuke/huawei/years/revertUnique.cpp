#include <string>
#include <iostream>
#include <set>
using namespace std;

int main(){
    string s;
    cin>>s;
    set<char> has_one;
    
    for(auto e=s.rbegin(); e!=s.rend(); e++){
    	if( has_one.find(*e) != has_one.end())
            continue;
        cout<<*e;
        has_one.insert(*e);
    }
    return 0;
}