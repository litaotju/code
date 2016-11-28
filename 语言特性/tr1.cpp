#include <iostream>
#include <memory>
#include <functional>
#include <tuple>

using namespace std;
using namespace std::placeholders;

class A{
    public:
    void f() const{
        cout<<"A::f()"<<endl;
    };
};

class B:public A{
        public:
        void f(){
            cout<<"B::f()"<<endl;
        }
};

int Add(int a, int b){
    return a+b;
}

int main(){
    const A a;
    a.f();
    B b;
    b.f();
    
    unique_ptr<B> pb(new B);
    cout<<pb.get()<<endl;
    
    shared_ptr<B> pb3(new B);
    cout<<" "<< pb3.get() <<endl;
    pb3.get()->f();
    
    //c++函数对象， <int (int, int) > 是一个函数签名
    function<int (int, int)> fadd = Add;
    
    cout<<fadd(1,2)<<endl;
    
    //把 fadd 函数的第一个参数绑定为1。返回一个 int (int) 类型的参数
    function<int (int) > fadd1 = bind(fadd, _1, 1);
    cout<<fadd1(100)<<endl;
    
    
    auto t1 = make_tuple(100, 200, 300);
    cout<<get<1>(t1)<<endl;
    ////下面这个会在编译器 报错误
    //cout<<get<3>(t1)<<endl;
    
    // 固定大小的容器
    array<int, 10> array1;
    cout<<array1[1]<<endl;
    
    return 0;
}