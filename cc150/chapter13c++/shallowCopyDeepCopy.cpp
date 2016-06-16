#include <cstring> // strlen, memcpy, NULL
#include <cassert>
#include <iostream>
using namespace std;
struct Test{
    //�����в�Ӧ�ó��������Ľṹ���壬��Ȼ�г�Աָ�������
    //��Ӧ���ڹ��캯��������������Ա��������Ϊ���ָ������ڴ��ɾ���ڴ�
    //����û���������ָ�롣
    char *ptr;
    
};

//ǳ����������ָ��ָ��ͬһ���ط�
void shallowCopy(Test *src, Test *target){
    target->ptr = src->ptr;
}

//���������ָ��ָ�������
void deepCopy(Test *src, Test *target){
    if(target->ptr!=NULL){
        //���delete�˲��� new����ĵ�ַ ��ô�죿
        delete target->ptr;
        target->ptr = NULL;
    }
    target->ptr = new char[ strlen(src->ptr)+1];
    
    //void * memcpy(void *target , void *source, int numofbytes)
    // target is returned
    memcpy(target->ptr, src->ptr, strlen(src->ptr)+1);
}

int main(){
    Test a,b;
    char * content = "This is content";
    a.ptr = content;
    char * contentb = "This is contentb";
    b.ptr = contentb;
    
    shallowCopy(&a, &b);
    assert(a.ptr==b.ptr);
    assert(b.ptr == content);
    cout<<"Shallow copy OKAY"<<endl;
    
    deepCopy(&a, &b);
    assert(a.ptr!=b.ptr);
    assert(b.ptr != contentb);
    cout<<"Deepcopy OKAY"<<endl;
    
    
    cout<<contentb<<endl;
}