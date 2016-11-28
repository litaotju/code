#include <vector> 
#include <iostream>
using namespace std;

template<class IterType>
void PrintIterValue(IterType iter){
    //定义 迭代器指向的类型名称
    typedef typename std::iterator_traits<IterType>::value_type value_type;
    value_type local = *iter;
    cout<<local<<endl;
}

int main(){
    vector<string> vs {"Hello vector", "Hello string"};
    vector<int> vi{1, 2};
    PrintIterValue< vector<int>::iterator >(vi.begin());
    PrintIterValue< vector<string>::iterator >(vs.begin());
    return 0;
}