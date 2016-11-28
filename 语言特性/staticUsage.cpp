#include <iostream>
using namespace std;
class A{
public:
    static int SInt;
    static void SPrint(){
        cout<<"This is a static method"<<endl;
    } 
    static const int ConstIntA;
};

int A::SInt = 0;
 const int A::ConstIntA = 0;

// B继承了 A类的 静态方法和静态变量
class B: public A{
     
};
 
 
 int main(){
    //在C++里，静态方法和静态变量，通过 className:: field_name or className::methodName 来调用
    A::SPrint();
    cout<<"A::SInt "<<A::SInt<<endl;
    cout<<"const A::ConstIntA "<< A::ConstIntA<<endl;
    B::SPrint();
    cout<<"B::Sint "<<B::SInt<<endl;
}