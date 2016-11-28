#include <iostream> // cout
#include <typeinfo> // badcast
#include <string>
using namespace std;

/*
dynamic_cast ������ͨ�����ڣ�������ʱ�� ʵ��ָ��������� ��������ָ�룬ת���������࣬
             �������� �����������в����ڻ���ɷ� ��һЩ���Ի��߷�����


dynamic_cast ������������ virtual ��Ա��ָ���������ʱ�� ������ʱ����ת����
                       �� virtual ��Ա��ָ����������ǣ��ڱ���������ת����
*/


class A{
int a;
public:
    A(int _a):a(_a){   
    }
    virtual void print(){
        cout<<"Class A print(), a: " << a<<endl;
    }
    
    // A��Ҫ���̳У������������һ�������������
    virtual ~A(){
        
    }
};

class B: public A{
int b;
public:
     B(int _a, int _b): A(_a), b(_b){
         
     }
     // ��A�и÷������и���
     void print(){
         cout<<"Class B print(), b: " << b <<endl;         
     }
     
     //�˷���ֻ����������B�� A������û���������
     void printBUnique(){
         cout<<"Class B printBUnique(), b:" <<b <<endl;
     }
     
     ~ B(){
         
     }
};

class C{
    int c;
    public:
    C(int _c): c(_c){
        
    }
    virtual void print(){
        cout<<"Class C print(), c: "<< c<< endl;
    }
};


int main(){
    // A��ָ��ָ����һ�� �������
    A *a1  = new A(10);
    // A���ָ��ָ����һ�����������
    A *a2 = new B(11, 20);
    
    C *c = new C(12);
    
    //��̬, ��ִ�� B::print()
    a2->print();
    
    //����a2 ʵ��ָ����B��Ķ���������ȴ�޷�ֱ��ʹ��
    // a2->printBUnique(); //��Ϊ a2��A���͵�ָ�룬���Ա������ᱨ��
    //Ϊ��ʹ�� a2->printBUnique() ���뽫a2ת���� B���ָ�롣������������ת������֮Ϊ RTTI
    //RUN TIME TYPE IDENTIFICATION 
    
    //1.
    //ʵ��ָ�� �����ָ�벻��dynamic_cast���������ָ�룬 dynamic_cast����ֵΪ0
    if(B *b = dynamic_cast<B *>(a1)){
        b->printBUnique(); // ��ִ����һ��
    }else{
        cout<<"Can not cast"<<endl;
    }
    
    //2.
    // dynamic_cast�����ã�������ɹ����׳� bad_cast�쳣
    try{
        B &b = dynamic_cast<B &>(*a1);
        b.printBUnique(); //����ִ����һ��
    }catch( bad_cast ){
        cout<< "Can not cast. throw a bad cast exception"<<endl;
    }
    
    //3.
    //ʵ��ָ�� ������� ����ָ�� �ܱ� cast����ȷ�������࣬��������ִ��ֻ����������еĳ�Ա����
    if(B *b = dynamic_cast<B *>(a2)){
        b->printBUnique();
    }else{
        cout<<"Can not cast"<<endl; //��ִ����һ��
    }
    
    //4.
    //û�м̳й�ϵֱ����֮���ָ�벻�ܽ���dynamic_cast ����
    if (B *b = dynamic_cast<B *>(c)){
        b->printBUnique();
    }else{
        cout<<"Can not cast C* to B*"<<endl;
    }
    
    
    // typeid (e) ���ر��ʽe������, ��һ�� typeinfo ��Ķ���
    cout<< typeid(a1).name()<<endl; 
    cout<< typeid(a2).name()<<endl;
    cout<< typeid(int).name()<<endl;
    cout<< typeid(string).name()<<endl;
   
    delete c;
    delete a2;
    delete a1;
}