#include <cstdio>
#include <iostream>
#include <string> // stoi, to_string
#include <algorithm>
using namespace std;

bool compareInverse(char a, char b){
    return a > b;
}

int main(){
    string str;
	string str_cpy;
    cin>>str;
    while(true){
		while(str.size() < 4){
            //在字符串前面 加字符，组成新的字符串： 
            //string = char + string;
            str = '0'+str;
        }
        str_cpy = str;
    	sort(str.begin(), str.end(), compareInverse);
    	sort(str_cpy.begin(), str_cpy.end());
        // stoi只有c++11可以使用，将字符串转化为整数
    	int a = stoi(str);
        int b = stoi(str_cpy);
        
        int result =  a - b;
        printf("%.4d - %.4d = %.4d", a, b, result);
        if(result == 0 || result==6174){
            break;
        }else{
            printf("\n");
        }
        //将整数转换为string类对象
        str = to_string(result);
    }
    return 0;
}