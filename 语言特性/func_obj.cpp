#include <iostream>
using namespace std;
/*
������ʾ�ɵ��ö���ĸ������ opeator () ������������������һ���ɵ��ö�����
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