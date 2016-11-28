#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

#define DEBUG false

int loggestCommonSubstring(const string &, const string &);

bool valid(const string & password){
    if(password.empty() || password.size() <= 8)
        return false;
    // 大写，小写字母，数字，符号必须各含有一个
    int hasAlpha = 0,  hasAlphaUp = 0,  hasNum = 0, hasPunc = 0;
    for(auto c: password){
        if( c >='a' && c<='z')
            hasAlpha = 1;
        else if (c>='A' && c<='Z')
            hasAlphaUp = 1;
        else if( c >= '0' && c<='9')
            hasNum = 1;
        else
            hasPunc = 1;
    }
    if((hasAlpha + hasAlphaUp + hasNum + hasPunc) < 3)
        return false;
    //不能包含长度超过2的子字符串
    for(int i = 3; i< password.size(); i++){
        int lcs = loggestCommonSubstring(password.substr(0,i), password.substr(i));
        if( lcs > 2){
            #if DEBUG
            cout<<"rules3: "<<  lcs<< endl;
            cout<< password.substr(0,i)<<endl;
            cout<< password.substr(i)<<endl;
            #endif
            return false;
        }
    }
    return true;
}

int loggestCommonSubstring(const string &a, const string &b){

    if(a.empty() || b.empty())
        return 0;
    vector<vector<int> > m(a.size(), vector<int>(b.size(), 0));    
    int indexA, indexB;
    int maxLength = 0;
    for(indexB = 0; indexB < b.size(); indexB++){
        m[0][indexB] = ((a[0]==b[indexB]) ? 1 : 0);
        maxLength = max( maxLength, m[0][indexB]); 
    }
    for(indexA = 1; indexA <a.size(); indexA++){
        m[indexA][0] = ((a[indexA] == b[0]) ? 1 : 0);
        maxLength = max(maxLength, m[indexA][0]);
    }
    int length = 0;
    for(indexA = 1; indexA < a.size(); indexA++){
        for(indexB = 1; indexB < b.size(); indexB++){
            //错了，实际上这里是最长公共子序列的求法了
            if( a[indexA] == b[indexB]){
                m[indexA][indexB] = m[indexA-1][indexB-1] + 1;
                maxLength  = max(maxLength, m[indexA][indexB]);
            }else{
                m[indexA][indexB] = 0;
            }
        }
    }
    return maxLength;
}

void testLCS(){
    int l = loggestCommonSubstring(string("abc"), string("abcd"));
    cout<<l<<endl;
    assert( l== 3);
    assert(loggestCommonSubstring( string(), string() ) == 0);
}
int main(){
    string password;
    while(getline(cin, password)){
        if(valid(password)){
            cout<<"OK"<<endl;
        }else{
            cout<<"NG"<<endl;
        }
    }
    // testLCS();
}