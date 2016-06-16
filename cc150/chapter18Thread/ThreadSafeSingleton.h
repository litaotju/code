/*
* 本程序实现了一个线程安装的 SingleTon单例类,使用了 C++11的线程锁
*/
#include <mutex>
#include <iostream>

template<class T>
class ThreadSafeSingleton{
private:
    static std::mutex lock;
    static T *object;
protected:
    ThreadSafeSingleton();
public:
    ThreadSafeSingleton<T> * instance();
};

ThreadSafeSingleton<T>::lock = std::mutex();
ThreadSafeSingleton<T>::object = nullptr;

T* ThreadSafeSingleton<T>::instance(){
    if(object==nullptr){
        lock.lock();
        //注意这里需要判断第二次，因为两个线程可能同时进入第一个判断语句
        //此时只需要第一个获得锁的线程创建对象。第二个不需要
        if(object == nullptr){
            object = new T;
        }
        lock.unlock();
    }
    return object;
}