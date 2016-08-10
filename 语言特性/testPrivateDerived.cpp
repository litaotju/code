#include <iostream>
using namespace std;
class A{
public:
    int a;
};

class B: public A{
    public:
    int b;
};

class C:private A{
public:
    int c;
};

void func(A & objA){
    cout<<&objA<<endl;
}


int main(){
    B objB;
    C objC;
    func(objB); // this is fine
    
    //因为是私有继承，所以在需要A的地方，不能直接使用C。
    // this can not compile, beacause A is an inaccessible base of C;
    func(objC);
}