#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    getline(cin, s);
    int firstNonSpaceTail = s.size()-1;
    while( firstNonSpaceTail >= 0 && s[firstNonSpaceTail]==' ')
        firstNonSpaceTail --;
    int cnt = 0;
    
    //Ö±µ½Îª¿Õ
    while( firstNonSpaceTail >= 0 && s[firstNonSpaceTail] != ' '){
        firstNonSpaceTail--;
        cnt++;
    }
    cout<<cnt;
    return 0;
}