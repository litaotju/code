/*
本例只要演示 C++类的继承当中的 namehiding 特性
也就是： 除非显示的指明使用基类当中的某一个函数的符号， 否则
只要子类定义了重载函数中的一个，那么基类的该组重载函数全部被隐藏。调用时会产生编译错误。
关于 隐藏机制可以参见网页：

[为什么C++需要名称隐藏](http://blog.csdn.net/wangdingqiaoit/article/details/46502399)

《Effective C++》里面说到， 除非是 virtual函数，否则不要轻易的hiding基类的函数
因为这使得： 子类不能完成基类的某些函数功能，因而子类不完全是 is-a 基类的对象。

*/
#include <iostream>
using namespace std;

class Base{
public:
    void func(){
        cout<<"Base::func()"<<endl;
    };
    void func(int a){
        cout<<"Base::func(int)"<<endl;
    }
};


class HidDerived: public Base{
public:
  // this will also hide the Base::func(int)
    void func(){
        cout<<"Derived::func()"<<endl;
    }
  
};

class NonHidDrived: public Base{
public:
    //使用这句话使得隐藏去除了，Base::func(int)可见
    using Base::func;
    
    void func(){
        cout<<"NonHidDrived::func()"<<endl;
    }
};

int main(){
    Base a;
    HidDerived d;
    
    // will give an compiltion error
    //d.func(1);
    
    //fine
    d.func();
    
    NonHidDrived d2;
    // this is fine
    d2.func(1);
    // cout<< Base::func(int)
    
    // this is fine
    d2.func();
}