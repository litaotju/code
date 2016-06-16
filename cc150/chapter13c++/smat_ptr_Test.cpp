#include "smart_ptr.h"
#include <iostream>
using namespace std;

class TestClass{
public:
    TestClass(int a = 1, char b= 'b'):mA(a), mB(b){
        cout<<"TestClass instance is created"<<endl;
    }
    ~TestClass(){
        cout<<"TestClass instance is deleted"<<endl;
    }
private:
    int mA;
    char mB;
};

smart_ptr<TestClass> testFunc(){
    //p1 指向了一个在堆上创建的对象。如果不进行显示的delete 这个对象就会成为
    //内存泄漏的一部分，使用了智能指针，会判断什么时候进行delete。这里由于p2 也指向了 new TestClass
    //创建的匿名对象。所以在函数内部并不会删除这个对象。出了函数之外才会删除
    smart_ptr<TestClass> p1 (new TestClass), p2 = p1;
    cout<<"Leaving a testFunc"<<endl;

    //这个函数不好，因为不能C++中一般不建议通过函数返回类或结构体对象
    return p1;
}

void testFunc2(){
    smart_ptr<TestClass> p2 = testFunc();
}

int main(){
    testFunc2();
    return 0;
}