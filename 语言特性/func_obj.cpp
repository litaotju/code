#include <iostream>
using namespace std;
/*
本例演示可调用对象的概念。重载 opeator () 操作符，即可以生成一个可调用对象类
*/
class FuncObj{
    public:
    void operator ()(){
            ++ call_cnt;
            cout<<"FuncObj is called for "<< call_cnt <<" times"<<endl;
        }
    
    private:
        static int call_cnt;
};

int FuncObj::call_cnt = 0;

int main(){
    
    FuncObj f;
    f();
    f();
    f();
    
}