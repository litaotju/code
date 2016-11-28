#include <stdexcept>
#include <iostream>
#include <cassert>
using namespace std;

const int MAXLEN  = 1000;

template<class T>
class Stack{
    T data[MAXLEN];
    int mTop;
public:
    Stack():mTop(0){
    }
    
    bool isEmpty(){
        return 0==mTop;
    }
    
    bool isFull(){
        return MAXLEN == mTop;
    }
    
    bool push(T item){
        if(isFull())
            return false;
        data[mTop++] = item;
        return true;
    }
    
    bool pop(){
        if(isEmpty())
            return false;
        --mTop;
    }
    
    // T top() throw(out_of_range){
    T top(){    
    if(isEmpty())
            throw out_of_range("The stack is empty");
        return data[mTop-1];
    }
};

void testStack(){
    Stack<int> s;
     try{
        s.top();
     }catch(out_of_range & error){
         cout<<error.what()<<endl;
     }
     assert(s.pop()==false);
     s.push(1);
     assert(s.top()==1);
     for(int i=0; i< MAXLEN-1; ++i){
         s.push(i);
     }
     assert(s.push(1)==false);
}


int main(){
    testStack();
}