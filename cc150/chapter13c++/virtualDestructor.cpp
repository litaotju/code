#include <iostream>
#include <cassert>
using namespace std;

int global = 0;

#define Graceful true

class Base{
    public:
        Base(){
            global++;
            cout<<"Base:: constructor called"<<endl;
        }
    #if Graceful
        virtual ~Base(){
            global--;
            cout<<"Base:: destructor called"<<endl;
        }
    #else
        ~Base(){
            global--;
            cout<<"Base:: destructor called"<<endl;
        }
    #endif
};

class Derived: public Base{
    public:
        Derived(){
            global++;
            cout<<"Derived:: constructor called"<<endl;
        }
        ~Derived(){
            global--;
            cout<<"Derived:: destructor called"<<endl;
        }
};

int main(){
    Base *pb = new Derived();
    delete pb;
    //if Graceful
    // Base:: const
    // Derived:: const
    // Derived:: destructor
    // Base::destructor
    #if Graceful
        //基类析构函数声明为 virtual会分别调用子类析构函数和基类构造函数
        // 所以是对称的，也是程序员想要的
        assert(global ==0);
    #else
        //基类析构函数不声明为 virtual, 不会调用子类的析构函数
        assert(global==1);
    #endif
}