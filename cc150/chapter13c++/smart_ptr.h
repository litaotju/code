//本文件中的智能指针只适合单线程使用
//智能指针的意思是，只需要开辟内存 不用管内存的释放
//只要引用该地址的所有变量都出了作用域（每一个出作用域都会调用一次析构函数），
//那么引用计数会变为0，从而释放被引用的内存区域。
#include <iostream>
using namespace std;

template<class T>
class smart_ptr{
public:
    //要不要默认构造函数？
    smart_ptr(T *ptr){
        //如果ptr指向指向null呢
        // assert（ptr！=NULL）
        ref = ptr;
        ref_count = new unsigned int;
        *ref_count = 1;
        cout<<"smart_ptr is initialized; "<<flush;
        printStat();
    }
    
    smart_ptr(smart_ptr<T> & sptr){
        cout<<"Copy a ref"<<endl;
        ref = sptr.ref;
        ref_count = sptr.ref_count;
        ++*ref_count;
        printStat();
    }
    
    smart_ptr<T> & operator = (smart_ptr<T> & sptr){
        if(this != &sptr){
            cout<<"Assigned a ref"<<endl;
            this->ref = sptr.ref;
            this->ref_count = sptr.ref_count;
            ++*ref_count;
            printStat();
        }
        return *this;
    }

    ~smart_ptr(){
        --*ref_count;
        cout<<"One ref is leaving; ";
        printStat();
        if(*ref_count == 0){
            delete ref;
            delete ref_count;
            // is this necessory?
            ref = NULL;
            ref_count = NULL;
            cout<<"All the ref is deleted"<<endl;
        }
    }

    T getValue(){
        return *ref;
    }

    void printStat(){
        cout<<"point to-> "<< ref << " count: "<< *ref_count<<endl;
    }

private:
    T * ref;
    unsigned int * ref_count;
};
