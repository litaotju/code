#include <vector>
#include <iostream>
using namespace std;

void printV(vector<int> v){
    for(auto e:v){
        cout<<e<<", ";
    }
    cout<<endl;
}

int unique(vector<int> & data){
    int result  = 0;
    for(auto e: data){
        result ^= e;
    }
    return result;
}

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    int x = 0;
    *num1 = 0, *num2 = 0;
    if(data.empty())
        return ;
    for(auto e : data){
        x = x^e;
    }
    cout<<x<<endl;
    int flag = 1;
    while(0== (flag&x) ){
        flag << 1;
    }
    cout<<flag<<endl;
    vector<int> part1, part2;
    for(auto e: data){
        if( e & flag)
            part1.push_back(e);
        else
            part2.push_back(e);
    }
    printV(part1);
    printV(part2);
    *num1 = unique(part1);
    *num2 = unique(part2);
}


int main(){
    int N;
    while(cin>>N && N>0){
        vector<int> v;
        int e;
        for(int i=0; i<N; i++){
            cin>>e;
            v.push_back(e);
        }
        int n1, n2;
        FindNumsAppearOnce(v, &n1, &n2);
        cout<<n1<<" "<<n2<<endl;
    }
}