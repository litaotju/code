/*
����ֻҪ��ʾ C++��ļ̳е��е� namehiding ����
Ҳ���ǣ� ������ʾ��ָ��ʹ�û��൱�е�ĳһ�������ķ��ţ� ����
ֻҪ���ඨ�������غ����е�һ������ô����ĸ������غ���ȫ�������ء�����ʱ������������
���� ���ػ��ƿ��Բμ���ҳ��

[ΪʲôC++��Ҫ��������](http://blog.csdn.net/wangdingqiaoit/article/details/46502399)

��Effective C++������˵���� ������ virtual����������Ҫ���׵�hiding����ĺ���
��Ϊ��ʹ�ã� ���಻����ɻ����ĳЩ�������ܣ�������಻��ȫ�� is-a ����Ķ���

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
    //ʹ����仰ʹ������ȥ���ˣ�Base::func(int)�ɼ�
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