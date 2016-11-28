#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <bitset>
using namespace std;
/*
题目描述

原理：ip地址的每段可以看成是一个0-255的整数，把每段拆分成一个二进制形式组合起来，然后把这个二进制数转变成
一个长整数。
举例：一个ip地址为10.0.3.193
每段数字             相对应的二进制数
10                   00001010
0                    00000000
3                    00000011
193                  11000001
组合起来即为：00001010 00000000 00000011 11000001,转换为10进制数就是：167773121，即该IP地址转换后的数字就是它了。
 
的每段可以看成是一个0-255的整数，需要对IP地址进行校验

输入描述:
输入 
1 输入IP地址
2 输入10进制型的IP地址


输出描述:
输出
1 输出转换成10进制的IP地址
2 输出转换后的IP地址

输入例子:
10.0.3.193
167969729

输出例子:
167773121
10.3.3.193
*/

//本题目要求进行IP地址转换

//点分十进制转整数
unsigned int dotToInteger(const string & input){
    if(input.empty())
        return 0;
    unsigned int result = 0;
    unsigned int  sec = 0;
    int start =0, end = 0, index = 0;
    while(start < input.size()){
        while( end < input.size() && input[end]!='.'){
            if(!(input[end] <='9' && input[end] >='0')){
                cout<<"illeagal input char: "<< input[end]<<endl;
                exit(1);
            }
            end++;
        }
        sec = stoi(input.substr(start, end-start));
        //cout<<sec<<endl;
        if(sec<0 || sec>255){
            cout<<"error, the section is illeagal: sec= "<<sec<<endl;
            exit(1);
        }
        //cout<<bitset<8>(sec)<<endl;
        result = result | (sec << (32-(++index)*8));
        //cout<< bitset<32>(result)<<endl;
        start = end+1;
        end = start;
    }
    return result;
}

// 二进制字符串转整数
int BinToInteger(string s){
    int ret = 0;
    if(s.empty())
        return 0;
    int i=0;
    while(i<s.size()){
        if(s[i]!='0' && s[i]!='1'){
            exit(1);
        }
        ret = ret*2 + s[i]-'0';    
        i++;
    }
    return ret;
}

//整数转点分十进制
string integerToDot(unsigned int input){
    //bitset::to_string方法
    string bits =  bitset<32>(input).to_string();
    string result;
    for(int i=0; i<4;i++){
        result += to_string(BinToInteger(bits.substr(8*i, 8)));
        if(i!=3){
            result += '.';
        }
    }
    return result;
}

int main(){
    string input;
    while(cin>>input){
        if(find(input.begin(), input.end(), '.') != input.end()){
            cout<<dotToInteger(input)<<endl;
        }else{
            cout<<integerToDot(stoul(input))<<endl;
        }
    }
    return 0;
}