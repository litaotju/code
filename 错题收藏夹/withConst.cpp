/*
���������˵����
    1. �ں������ƣ�����������ֵ ��ͬ������£�����const�Ͳ���const���η��ĺ���������ͬһ���������������������ǵ�����������������
    2. ������������ͬ������£�const�����constָ����� ��const���η��ĺ�����
        ��const������÷�const���η��ĺ���
    3. const�����β�ʱ�� ��const��ʵ���ں����ᱻת��Ϊconst����һת��Ϊ��������Ч��
*/
#include <iostream>
using namespace std;

class A{
    public:
    virtual void f(){
        cout<<"A::f()"<<endl;
    }
    void f() const{
        cout<<"A::f()const"<<endl;
    }
};

class B: public A{
public:
    void f(){
        cout<<"B::f()"<<endl;
    }
    void f() const{
        cout<<"B::f()const"<<endl;
    }
};

void g(const A * a){
    a->f();
}

int main(int argc, char * argv[]){
    
    A const *a = new A();
    a->f();
    A  *aa = new A();
    aa->f();
    //�������
    //A::f()const
    //A::f()
    //˵�� 1.��const�Ͳ���const�ĺ����ǲ�һ���ġ�
    //     2. constָ�룬�����˶�Ӧ�ļ�const���εĺ���
    
    g(a);
    g(aa);
    //�������
    // A::f() const
    // A::f() const
    //˵�������ݸ�������ָ���ں����ڲ��Ѿ�const����
    
    
    A *ab = new B();
    ab->f();
    g(ab);
    //�������
    //B::f()
    //A::f()const
    //��Ϊ: virtual void f()�������Զ�̬��Ϊǰ����� virtual�ؼ��֣�void f() const����û�ж�̬
        
    
    A const *const_ab = new B();
    const_ab->f();
    g(const_ab);

    //�������
    //A::f() const
    //A::f() const
    //��Ϊ void f() constû�ж�̬�� ֱ�ӵ��ø�����
}