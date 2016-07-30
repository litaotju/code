#include <iostream>
// #include <memory>
#include <string>
#include <vector>
using namespace std;

bool canTrunc(const vector<string> & s){
    if(s.empty())
        return true;
    int dict[26];
    for(int i=0; i<26; i++)
        dict[i] = 0;
    for(int i=0; i< s.size(); i++){
        dict[ s[i][0] -'a' ] += 1;
        dict[ s[i][s[i].size()-1] - 'a' ] -= 1;
    }
    bool has_head = false;
    bool has_tail = false;
    
    for(int i =0; i<26; i++){
        if(dict[i] == 1){
            if(has_head){
                return false;
            }
            has_head = true;
        }
        else if(dict[i] == -1){
            if(has_tail){
                return false;
            }
            has_tail = true;
        }else if(dict[i] != 0){
            //cout<<"fAAAalse"<<endl;
           return false;
           
        }
    }
    
    return has_head && has_tail;
}

int main(){
    int N;
    while(cin>>N){
        vector<string> words;
        string s;
        for(int i =0; i<N; ++i){
             cin>>s;
            words.push_back(s);
             //cout<<s<<endl;
        }
        if(canTrunc(words))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
}