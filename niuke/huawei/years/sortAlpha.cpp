#include <string>
#include <iostream>
using namespace std;

bool isAlpha(char c){
    return (c >='a' && c<='z') || (c >='A' && c<='Z');
}

//忽略大小写进行比较
bool lgIgnoreCase(char a, char b){
    if( a >= 'A' && a<='Z'){
        a = 'a' + a-'A';
    }
    if( b >='A' && b <='Z' ){
        b = 'a' + b-'A';
    }
    return a < b;
}

int main(){
    string s;
    //cout<<lgIgnoreCase('a', 'A')<<endl;
    while(getline(cin, s)){
        for(int i = 0; i<s.size()-1; i++){
            //一遍冒泡排序
            for( int j = s.size()-1; j>i; j--){
                if(!isAlpha(s[j]))
                    continue;
                int preAlpha = j-1;
                while(preAlpha >= i && !isAlpha(s[preAlpha]))
                    preAlpha--;
                if( !isAlpha(s[preAlpha]) )
                    break;
                if( lgIgnoreCase(s[j], s[preAlpha]) ){
                    char temp = s[j];
                    s[j] = s[preAlpha];
                    s[preAlpha] = temp;
                }
            }
        }
        cout<<s<<endl;
    }    
}