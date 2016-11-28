#include <vector>
#include <set>
#include <iostream>
using namespace std;

void testRangeFor(){
    cout<<"testRangeForSet"<<endl;
    vector<int> v = {1,2,3,4,5,6};
    
    //取v中的每一个元素值为e
    for(auto e:v){
        cout<<e<<endl;
        e *= 2; //所以这句话并不能改变 v中的元素值
    }
    
    //取v中的每一个元素 引用为e
    for(auto & element:v){
        cout<<element<<endl;
        element *= 2;
    }
    
    //观察进过上面第二个循环之后的向量的值，每一个元素都乘以2
    for(auto e:v){
        cout<<e<<endl;
    }
}


void testRangeForSet(){
    cout<<"testRangeForSet()"<<endl;
    set<int> seta = {1,9,3,19, 2};
    //即时 set没有按照顺序初始化，但是
    //使用下面的循环得到的 每一个元素仍然是按照从小到大的顺序的。
    for(auto e:seta){
        cout<<e<<endl;
    }
    
    for(auto &e: seta){
        cout<<e<<endl;
        // error , because the key in set can not be alternate
        // so e is readonly
        //e *= 2;
    }
}

int main(){
    testRangeFor();
    testRangeForSet();
}