#include <iostream>
using namespace std;

/*
name hiding in c++
    重载对于跨作用域是无效的，也就是重载只能在一个类的内部见到
    也就是override 一个的基类的函数时，基类的所有同名函数均不可见
*/

class First{
public:
    virtual void methodA(int a){
        cout<<"First"<<endl;
    }
    
    virtual void methodA(int a, int b){
        cout<<"Second"<<endl;
    }
};


class SecondClass: public First{
public:
    void methodA(int a){
        cout<<"Three"<<endl;
    }
    // First::methodA(int) 被覆盖，也被隐藏
    // First::methodA(int,int) 直接被隐藏，本类的实例无法直接调用该函数
};


class ThirdClass: public First{
public:
    void methodA(int a){
        cout<<"Five"<<endl;
    }
    
    void methodA(int a, int b){
        cout<<"Six"<<endl;
    }
};


int main(){
    First *pf;
    
    SecondClass a;
    a.methodA(1); // Three
    
    // call the SecondClass::methodA(int, int) does not exsits
    // because the SecondClass defines a function methodA(int), 
    //          this hiding the parent's all overloaded functions methodA
    //a.methodA(1,1); // is not leagal to call this
    
    //但是在这个例子中 由于 基类的函数都生命为virtual类型的，
    // 所以可以通过多态机制访问到基类的methodA(int, int)
    //通过指针仍然能访问到 FirstClass::methodA(int, int)
    pf = &a; 
    pf->methodA(1);   //Three
    pf->methodA(1,1); //Second
    
    
    ThirdClass b;
    b.methodA(1); // Five 
    b.methodA(1,1); // Six
    
    pf = &b;
    pf->methodA(1);   // Five
    pf->methodA(1,1); // Six
}