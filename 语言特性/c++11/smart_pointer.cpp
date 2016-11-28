#include <memory>  // auto_ptr, shared_ptr, make_shared
#include <iostream>
using namespace std;

class A{
public:
    A(){
        cout<< "A()"<<endl;
    }
    ~A(){
        cout<< "~A()"<<endl;
    }
};

//c++11
// 1 use 'auto' when you can, and when it's convinient
// 2 use smart_pointer


void testAutoPtr(){
    auto a = auto_ptr<A>(new A());
    cout<<"leaving testAutoPtr()"<<endl;
    //自动释放内存
}

void testRawPtr(){
    auto a = new A();
    cout<<"leaving testRawPtr()"<<endl;
    //内存泄漏
}

void testSharedPtr(){
    auto a = make_shared<A>();
    auto b = shared_ptr<A>(new A());
    auto c = b;
    cout<<"leaving testSharedPtr"<<endl;
    //自动释放内存
}

void testUniquePtr(){
    auto a = unique_ptr<A>(new A());
    //unique_ptr 不允许复制，所以下面的代码无法通过编译
    //auto b = a;
    cout<<"leaving testUniquePtr"<<endl;
}

int main(){
    testAutoPtr();
    testSharedPtr();
    testUniquePtr();
    testRawPtr();
}