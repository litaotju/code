/*
ACM Coder 1002
Problem Description
I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.

Sample Input
2
1 2
112233445566778899 998877665544332211

Sample Output
Case 1:
1 + 2 = 3

Case 2:
112233445566778899 + 998877665544332211 = 1111111111111111110
*/
#include <iostream>
#include <string>
#include <deque>
using namespace std;

string sumBig(string & A, string & B){
	int minLength = A.length() < B.length() ? A.length(): B.length();
	int maxLength = A.length() > B.length() ? A.length(): B.length();
    bool isAmore = A.length() > B.length() ? true: false;
    bool equalLength = (A.length() == B.length());
    
    string::iterator itA = A.end()-1, itB = B.end()-1;
    deque<char> result;
    
    char carry = '0';
    char sum = 0;
    for(int i = 0; i< minLength; itA--, itB--, i++){
        sum = (*itA-'0') + (*itB -'0') + (carry-'0');
        if(sum > 9){
            carry = '1';
            sum = (sum - 10) + '0';
        }
        else{
            carry = '0';
            sum  = sum + '0';
        }
        result.push_front(sum);
    }
    string::iterator it ;
    string::iterator it_begin;
    
    if(equalLength){ //长度相等，那么让it == it_begin 后面就不需要进行while循环，继续进位了
        it = A.begin()-1;
        it_begin = A.begin();
    }else if( !isAmore ){ // A has less chars than B
        it = itB;
        it_begin = B.begin();
    }else{ //  B has less chars than A
        it = itA;
        it_begin = A.begin();
    } 
    while(it >= it_begin ){
        sum = (*it -'0') + (carry - '0');
        if(sum >= 10){
            carry = '1';
            sum = (sum-10) + '0';
        }
        else{
            carry = '0';
            sum  = sum + '0';
        }
        result.push_front(sum);
        it--;
    }
    if(carry != '0'){
        result.push_front('1');
    }
    string result_string;
    for( deque<char>::iterator it_r = result.begin(); it_r != result.end(); it_r++){
        result_string.push_back(*it_r);
    }
    return result_string;
}

int main(int argc, char * arhv[]){
    int T;
    cin>>T;
    string A, B;
    int i = 0;
    while(i < T){
        i++;
        cin>>A>>B;
        cout<<"Case "<<i<<":"<<endl;
        cout<<A<<" + "<<B<<" = " << sumBig(A, B)<<endl;
        //注意，不是每一个结果后面跟一个空行，而是两个结果之间根一个空行.
        //所以输出结构时，要判断后面还有没有需要继续计算的东西
        if( i<T)
            cout<<endl;
    }
    return 0;
}

