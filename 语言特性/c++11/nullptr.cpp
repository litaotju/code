#include <iostream>

using namespace std;

void testNullPtr(){
    int * a = nullptr;
    //不输出
    if(a != nullptr)
        cout<<"a:"<< *a<<endl;
    int b = 10;
    a = &b;
    //输出
    if(a != nullptr)
        cout<<"a:"<< *a<<endl;
    a = nullptr;
    //输出
    if(a==nullptr)
        cout<<"a is nullptr"<<endl;
}

int main(){
    testNullPtr();
}