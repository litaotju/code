#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string deleteLeastChar(const string & s){
    string new_string;
    vector<int> freq(26, 0);
    for(auto c: s){
        freq[c-'a'] += 1;
    }
    
    int min_freq = 0;
    for( int i = 0; i<26; i++){
        if(min_freq == 0){
            min_freq = freq[i];
        }else if(freq[i] !=0 ){
            min_freq = min(freq[i], min_freq);
        }
    }
    for(auto c:s){
        if(freq[c-'a'] == min_freq){
            continue;
        }
        new_string.push_back(c);
    }
    return new_string;
}

int main(){
    string s;
    while(getline(cin, s)){
        cout<<deleteLeastChar(s)<<endl;
    }
}