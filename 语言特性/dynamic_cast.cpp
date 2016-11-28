#include <iostream> // cout
#include <typeinfo> // badcast
#include <string>
using namespace std;

/*
dynamic_cast 操作符通常用于，在运行时将 实际指向派生类的 基类类型指针，转换成派生类，
             进而可以 调用派生类中不属于基类成分 的一些属性或者方法。


dynamic_cast 操作符用于有 virtual 成员的指针或者引用时， 在运行时进行转换。
                       无 virtual 成员的指针或者引用是，在编译器进行转换。
*/


class A{
int a;
public:
    A(int _a):a(_a){   
    }
    virtual void print(){
        cout<<"Class A print(), a: " << a<<endl;
    }
    
    // A类要被继承，所以最好声明一个虚的析构函数
    virtual ~A(){
        
    }
};

class B: public A{
int b;
public:
     B(int _a, int _b): A(_a), b(_b){
         
     }
     // 对A中该方法进行覆盖
     void print(){
         cout<<"Class B print(), b: " << b <<endl;         
     }
     
     //此方法只属于派生类B， A类里面没有这个方法
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
    // A类指针指向了一个 基类对象
    A *a1  = new A(10);
    // A类的指针指向了一个派生类对象
    A *a2 = new B(11, 20);
    
    C *c = new C(12);
    
    //多态, 将执行 B::print()
    a2->print();
    
    //但是a2 实际指向了B类的对象，在这里却无法直接使用
    // a2->printBUnique(); //因为 a2是A类型的指针，所以编译器会报错。
    //为了使用 a2->printBUnique() 必须将a2转换成 B类的指针。可以在运行是转换，称之为 RTTI
    //RUN TIME TYPE IDENTIFICATION 
    
    //1.
    //实际指向 基类的指针不能dynamic_cast成派生类的指针， dynamic_cast返回值为0
    if(B *b = dynamic_cast<B *>(a1)){
        b->printBUnique(); // 不执行这一句
    }else{
        cout<<"Can not cast"<<endl;
    }
    
    //2.
    // dynamic_cast成引用，如果不成功，抛出 bad_cast异常
    try{
        B &b = dynamic_cast<B &>(*a1);
        b.printBUnique(); //不会执行这一句
    }catch( bad_cast ){
        cout<< "Can not cast. throw a bad cast exception"<<endl;
    }
    
    //3.
    //实际指向 派生类的 基类指针 能被 cast成正确的派生类，进而可以执行只有派生类才有的成员函数
    if(B *b = dynamic_cast<B *>(a2)){
        b->printBUnique();
    }else{
        cout<<"Can not cast"<<endl; //不执行这一句
    }
    
    //4.
    //没有继承关系直的类之间的指针不能进行dynamic_cast 比如
    if (B *b = dynamic_cast<B *>(c)){
        b->printBUnique();
    }else{
        cout<<"Can not cast C* to B*"<<endl;
    }
    
    
    // typeid (e) 返回表达式e的类型, 即一个 typeinfo 类的对象
    cout<< typeid(a1).name()<<endl; 
    cout<< typeid(a2).name()<<endl;
    cout<< typeid(int).name()<<endl;
    cout<< typeid(string).name()<<endl;
   
    delete c;
    delete a2;
    delete a1;
}