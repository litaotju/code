#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool comp(int a, int b){
    return a > b;
}

int max_beauty(string name){
    if(name.empty())
        return 0;
    vector<int> freq(26, 0);
    for(auto c: name){
        // c>='a' && c<='z'
        freq[c-'a'] += 1;
    }
    sort(freq.begin(), freq.end(), comp);
    int beauty = 0;
    for(int i=0; i<26 && freq[i]>0; i++){
        beauty += (26-i)*freq[i];
    }
    return beauty;
}


int main(){
    int N;
    cin>>N;
    string name;
    for(int i=0; i<N;i++){
        getline(cin, name);
        cout<<max_beauty(name)<<endl;
    }
    return 0;
}