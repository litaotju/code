#include <iostream>
using namespace std;

/*
name hiding in c++
    ���ض��ڿ�����������Ч�ģ�Ҳ��������ֻ����һ������ڲ�����
    Ҳ����override һ���Ļ���ĺ���ʱ�����������ͬ�����������ɼ�
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
    // First::methodA(int) �����ǣ�Ҳ������
    // First::methodA(int,int) ֱ�ӱ����أ������ʵ���޷�ֱ�ӵ��øú���
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
    
    //��������������� ���� ����ĺ���������Ϊvirtual���͵ģ�
    // ���Կ���ͨ����̬���Ʒ��ʵ������methodA(int, int)
    //ͨ��ָ����Ȼ�ܷ��ʵ� FirstClass::methodA(int, int)
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