#include <string.h>
#include <iostream>
using namespace std;

bool isRoateSubstr(char *s1, char *s2){
    char *ss = new char[2*strlen(s1)+1];
    strcpy(ss, s1);
    strcpy(ss+strlen(s1), s1);
    if(strstr(ss, s2)==NULL)
        return false;
    return true;
}

int main(){
    char A[]="ABCD";
    char B[]= "CDA";
    cout<<isRoateSubstr(A,B);
}