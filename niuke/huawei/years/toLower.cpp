#include <string>
#include <iostream>
using namespace std;

int main(){
    char c;
    cin>>c;
    cout<< static_cast<char>('a'+ c-'A')<<endl;
}