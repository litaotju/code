#include <cstring> // strlen, memcpy, NULL
#include <cassert>
#include <iostream>
using namespace std;
struct Test{
    //开发中不应该出现这样的结构定义，既然有成员指针变量。
    //就应该在构造函数（或者其他成员函数）中为这个指针分配内存和删除内存
    //否则没法管理这个指针。
    char *ptr;
    
};

//浅拷贝，两个指针指向同一个地方
void shallowCopy(Test *src, Test *target){
    target->ptr = src->ptr;
}

//深拷贝，复制指针指向的内容
void deepCopy(Test *src, Test *target){
    if(target->ptr!=NULL){
        //如果delete了不是 new分配的地址 怎么办？
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