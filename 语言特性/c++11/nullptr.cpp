#include <iostream>

using namespace std;

void testNullPtr(){
    int * a = nullptr;
    //�����
    if(a != nullptr)
        cout<<"a:"<< *a<<endl;
    int b = 10;
    a = &b;
    //���
    if(a != nullptr)
        cout<<"a:"<< *a<<endl;
    a = nullptr;
    //���
    if(a==nullptr)
        cout<<"a is nullptr"<<endl;
}

int main(){
    testNullPtr();
}