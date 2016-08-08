#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

char processChar(char &c){
    vector<int> bits(4,0);
    if( c >='0' && c<='9'){
        c = c-'0';
    }else if( c>='A' && c<='F'){
        c = 10+ c-'A';
    }else if( c>='a' && c<='f'){
        c = 10 + c-'a';
    }else{
        return c;
    }
    bits[0] = (1 & c)? 1:0;
    bits[1] = (2 & c)? 1:0;
    bits[2] = (4 & c)? 1:0;
    bits[3] = (8 & c)? 1:0;
    int temp;
    temp = bits[3];
    bits[3] = bits[0];
    bits[0] = temp;
    temp = bits[1];
    bits[1] = bits[2];
    bits[2] = temp;
    temp = 8* bits[3] + 4* bits[2] + 2*bits[1] + bits[0];
    if( temp >=0 && temp<=9){
        return static_cast<char>('0'+temp);
    }else{
        return static_cast<char>('A'+temp-10);
    }
}

string process(const string &a, const string &b){
    string merge;
    merge = a + b;
    string even, odd;
    for(int i=0; i<merge.size(); i++){
        if( i%2==0)
            even.push_back(merge[i]);
        else
            odd.push_back(merge[i]);
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    string result;
    int i=0;
    while(i<even.size() && i<odd.size()){
        result.push_back(even[i]);
        result.push_back(odd[i]);
        i++;
    }
    if(i<even.size()){
        result.push_back(even[i]);
    }
    if(i<odd.size()){
        result.push_back(odd[i]);
    }
    for(auto & c:result){
        c = processChar(c);
    }
    return result;
}

int main(){
    string a, b;
    while(cin>>a>>b){
        cout<<process(a,b)<<endl;
    }
}