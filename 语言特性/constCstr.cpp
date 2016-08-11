#include <iostream>
using namespace std;
int main(){
    const char *p1 = "This is a string";
    const char *p2 = "This is a string";
    //p1[1] = 'G';
    int N;
    cin>>N;
    char s[N];
    cout<< (p1==p1) <<endl;
    cout<<p1<<endl;
    cout<<p2<<endl;
    return 0;
}

int func(int N){
    char ss[N];
    cout<<"funt"<<endl;
    return N;
}