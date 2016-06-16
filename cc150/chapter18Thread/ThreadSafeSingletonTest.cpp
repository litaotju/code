#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

#include "ThreadSafeSingleton.h"
using namespace std;

// std::mutex
mutex mtx;

TestClass{
    int mA;
public:
    TestClass(ma = 0):mA(ma){
        cout<<"TestClass instances is created"<<endl;
    }
    void printSelf(){
        mtx.lock();
        std::cout<<"Object address is " object<<std::endl;
        mtx.unlock();
    }
};

void testFunc(){
    // getInstance return a TestClass *
    ThreadSafeSingleton<TestClass>::getInstance()->printSelf();
}

int main(){
    vector<thread> threads;
    //create 10 threads with each has a function testFunc
    for(int i =0; i<10; i++){
        thread2.push_back(thread(testFunc));
    }
    cout<<"threads are doing"<<endl;
    
    // c++ 11 sytax
    for(auto & t:threads){
        t.join();
    }
    return 0;
}
