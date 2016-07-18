#include <deque>
#include <iostream>
using namespace std;

int main(){
    deque<int> Q;
    
    Q.pop_front();
    
    cout<<Q.front()<<endl;
    throw exception();
}