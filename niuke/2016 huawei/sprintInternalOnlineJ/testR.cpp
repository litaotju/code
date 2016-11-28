#include <iostream>
#include <string>
using namespace std;

inline bool isAlpha(char c){
    return (c>='a' && c<='z') || ( c>='A' && c<='Z');
}

int main(){
    string s;
    string result;
    cin>>s;
    int start = 0, end = 0;
    int cur_cnt = 0;
    while(end < s.size()){
        while(s[end] == s[start] || !isAlpha(s[end]) ){ //相等或者是数字是end后移
            ++end;
            if( !isAlpha(s[end]) ){ //如果是数字，什么都不做
                continue;
            }else{ //不是数字
                ++cur_cnt;
            }
        }
        cout<<s[start]<<cur_cnt;
        cur_cnt =0;
        start = end;
    }
    return 0;
}