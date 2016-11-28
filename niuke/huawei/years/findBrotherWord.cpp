#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isBrother(const string & a, const string &b ){
    vector<int> freqA(26, 0), freqB(26, 0);
    for(auto e: a){
        freqA[e-'a'] += 1;
    }
    for(auto e: b){
        freqB[e-'a'] += 1;
    }
    int i=0;
    while(i<26 && freqA[i] == freqB[i] ){
        i++;
    }
    if(i==26)
        return true;
    else
        return false;
}


int main(){
    int N;
    int th;
    while(cin>>N && N > 0){
        vector<string> words;
        string s;
        for(int i=0; i<N; i++){
            cin>>s;
            words.push_back(s);
        }
        cin>>s;
        cin>>th;        
        vector<string> brothers;
        int cnt = 0;
        for(int i=0; i<N; i++){
            if( words[i]==s )
                continue;
            if(isBrother(s, words[i])){
                cnt++;
                brothers.push_back(words[i]);
            }
        }
        // for(auto & e: brothers){
        //     cout<<e<<endl;
        // }
        sort(brothers.begin(), brothers.end());
        cout<<cnt<<endl;
        cout<<brothers[th-1]<<endl;
    }
}