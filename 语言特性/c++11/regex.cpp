#include <regex>
#include <string>
#include <iostream>

using namespace std;

void replace(string & subject, const  string & pattern, const string & repl){
    regex reg(pattern);
    regex_replace(subject, reg,  repl);
    cout<<subject<<endl;
}

int main(){
    string subject, pattern, repl;
    cout<<"Plz enter sub: ";
    getline(cin, subject);
    cout<<"plz enter pattern: ";
    getline(cin, pattern);
    cout<<"plz enter repl ";
    getline(cin, repl);
    replace(subject, pattern, repl);
    cout<<"result is: "<<endl;
    cout<<subject;
    return 0;
}