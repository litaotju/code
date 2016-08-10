#include<iostream>
#include <cctype> // isdigit, isspace, isalpha函数
#include <string>
using namespace std;

int main(){
	string line;
    while(getline(cin, line)){
        int alphaCnt = 0, numCnt = 0, spaceCnt = 0, otherCnt = 0;
        for(auto c: line){
			if(isalpha(c))
                alphaCnt ++;
            else if(isdigit(c))
                numCnt ++;
            else if (isspace(c))
                spaceCnt ++;
            else
               	otherCnt ++;
        }
        cout<<alphaCnt<<endl;
        cout<<spaceCnt <<endl;
        cout<<numCnt <<endl;
        cout<<otherCnt <<endl;
    }
}