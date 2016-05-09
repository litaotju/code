#include <iostream>
using namespace std;

/*
本程序主要说明几个问题
1. 静态非常量成员变量必须在类外进行初始化
2. 静态常量成员变量可以在类内也可以在类外进行初始化

具体的要求应该和编译器有关，本测试程序在 mingw32 g++ 4.7.2运行通过
*/

class A{
public:
    static int staticMemA;
    //static int staticMemA = 1; //error: 不能在类内初始化
    static const int staticConstMemA = 2; //*1 静态成员常量可以在类内进行初始化
    static const double staticConstDoubleMemA; 
};

//*2 静态非常量成员变量必须在类外进行初始化
int A::staticMemA = 1;

//*3 静态常量成员变量可以在类外进行初始化，同时必须加const修饰符
const double A::staticConstDoubleMemA = 3.2;
double A::staticConstDoubleMemA = 3.2; //error

int main(){
    cout<<A::staticMemA<<endl;
    cout<<A::staticConstMemA<<endl;
    cout<<A::staticConstDoubleMemA<<endl;
}