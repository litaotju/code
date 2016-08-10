#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

char upper(char c){
    if(c >='a' && c<='z'){
        return c-'a'+'A';
    }else
        return c;
}

int main(){
    string cipher, plain;
    while( getline(cin, cipher) && getline(cin, plain)){
        string valid_cipher;
        vector<int> dict(26, 1);
        for(auto c: cipher){
            int index;
            if(c>='a' && c<='z'){
                index = c -'a';
            }else if( c>='A' && c<='Z'){
                index = c- 'A';
            }else{
                assert(false);
            }
            if( dict[index]==1){
                valid_cipher += upper(c);
            }
            dict[index] = 0;
        }
        for(int i=0; i<26; i++){
            //如果没有出现在cipher中，则按照顺序附在后面
            if(dict[i] == 1)
                valid_cipher += 'A' + i;
        }
        //cout<<valid_cipher<<endl;
        string result;
        for( auto c: plain){
            int index;
            if( c>='a' && c<='z' ){
                index = c-'a'; // 明文在字母表中的位置
                //同位置的密文减去 'A', 就是密文在字母表中的位置 + ‘a’就是密文
                result += ('a' + (valid_cipher[index]-'A'));
            }else if( c>='A' && c<='Z'){
                index = c-'A';
                result += ('A' + (valid_cipher[index]-'A'));
            }else{
                result += c;
            }
        }
        cout<< result<<endl;
    }
    return 0;
}