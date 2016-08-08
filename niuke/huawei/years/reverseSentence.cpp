#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void  reverseSentence(string & s){
    reverse(s.begin(), s.end());
    auto startW = s.begin(), endW = s.begin();

    while(startW !=s.end()){
        while(endW != s.end() && *endW !=' '){
            endW++;
        }
        reverse(startW, endW);
        if( endW == s.end()){
            break;
        }
        endW++;
        startW = endW; 
    }
}


int main(){
    string line, newline;
    while(getline(cin, line)){
        for(auto c: line){
            if( c>='a' && c<='z' || (c>='A'&& c<='Z') ){
                newline.push_back(c);
            }else{
                if(newline.empty())
                    continue;
                else if( newline.back()!=' ')
                    newline.push_back(' ');
            }
        }
        if(newline.back()==' ')
            newline.pop_back();
        reverseSentence(newline);
        cout<<newline<<endl;
    }
}