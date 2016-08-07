#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    reverse(s.begin(), s.end());
    auto cur = s.begin();
    while(cur != s.end()){
        auto w_start = cur, w_end = cur;
        while(w_end!=s.end() && *w_end != ' '){
            w_end++;
        }
        if( w_end==s.end())
            cur = w_end;
        else
            cur = w_end+1;
        //注意 反转的时候 不含 w_end
        reverse(w_start, w_end);
    }
    cout<<s;
}