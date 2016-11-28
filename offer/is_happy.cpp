#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

    bool isHappy_R(int cur, int ori){
        if(cur == ori){
            return false;
        }
        char * s =  new char[100];
        sprintf(s, "%d", cur);
        
        int next = 0;
        while( *s != '\0'){
            next += (*s-'0')^2;
            s += 1;
        }
		cout<< "next: " << next << endl;
        if(next == 1){
            return true;
        }
        else {
            return isHappy_R(next, ori);
        }
    }
	
    bool isHappy(int n) {
        return isHappy_R(n,n);
    }

int main(){
	cout<<"19 " << isHappy(19) << endl;
	cout<<"91 " << isHappy(91) << endl;
}