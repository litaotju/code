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
    //�Զ��ͷ��ڴ�
}

void testRawPtr(){
    auto a = new A();
    cout<<"leaving testRawPtr()"<<endl;
    //�ڴ�й©
}

void testSharedPtr(){
    auto a = make_shared<A>();
    auto b = shared_ptr<A>(new A());
    auto c = b;
    cout<<"leaving testSharedPtr"<<endl;
    //�Զ��ͷ��ڴ�
}

void testUniquePtr(){
    auto a = unique_ptr<A>(new A());
    //unique_ptr �������ƣ���������Ĵ����޷�ͨ������
    //auto b = a;
    cout<<"leaving testUniquePtr"<<endl;
}

int main(){
    testAutoPtr();
    testSharedPtr();
    testUniquePtr();
    testRawPtr();
}