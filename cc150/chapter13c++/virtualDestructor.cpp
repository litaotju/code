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
        //����������������Ϊ virtual��ֱ�����������������ͻ��๹�캯��
        // �����ǶԳƵģ�Ҳ�ǳ���Ա��Ҫ��
        assert(global ==0);
    #else
        //������������������Ϊ virtual, ��������������������
        assert(global==1);
    #endif
}