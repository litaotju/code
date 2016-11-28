/*
ACM coder 1005 Problem Description
A number sequence is defined as follows:

f(1) = 1, f(2) = 1, f(n) = (A * f(n - 1) + B * f(n - 2)) mod 7.

Given A, B, and n, you are to calculate the value of f(n).
Input
The input consists of multiple test cases. Each test case contains 3 integers A, B and n on a single line (1 <= A, B <= 1000, 1 <= n <= 100,000,000). Three zeros signal the end of input and this test case is not to be processed.
Output
For each test case, print the value of f(n) on a single line.
Sample Input
1 1 3
1 2 10
0 0 0
Sample Output
2
5
*/

#include <iostream>
#include <cassert>
using namespace std;

int F(int A, int B, int n){
    int f[201];
    f[1]=f[2] =1;
    if(n <=2){
        return 1;
    }
    int cnt=0;
    int i;
    // A. B不同，则函数的周期不同。所以每一次输入A.B都需要查表
    //由于 f每次都是取模运算。所以每一个f的可能取值只有0-6。所以总共的状态数是49
    //所以周期最大是49
    for(i=3; i<=200; i++){
        f[i] = (A*f[i-1] + B*f[i-2])%7;
        if(f[i]==1 && f[i-1] ==1)
            break;
        if(f[i]==0 && f[i-1] ==0){ //陷阱 A=7 B=7则后面一直是0
            cnt =1;
            break;
        }
    }
    if(cnt) return 0;
    if(i>n) return f[n];
    i-=2; //周期数
    n %= i;
    if(n==0) n=i;
    return f[n];
}

int main(int argc, char * argv[]){
    int A, B, n;
    while(cin>>A>>B>>n){
        if( A==0 && B==0 && n==0){
            break;
        }
        cout<< F(A, B, n)<<endl;
    }
    return 0;
}