#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    string result;
    if( strs.empty()){
        return result;
    }
    int min_length  = strs[0].size();
    for(int i = 0 ; i < strs.size(); i++){
        if( strs[i].size() < min_length){
            min_length = strs[i].size();
        }
    }
    
    cout<<min_length<<endl;
    if(min_length == 0){
        return result;
    }
    int lcp_length = 0;
    for( int j = 0; j < min_length; j++){
        char s = strs[0][j];
        for( int i = 1; i < strs.size(); i++){
            if( s != strs[i][j]){
                lcp_length = j;
                return strs[0].substr(0, lcp_length);
            }
        }
    }
}

int main(){
    unsigned int  n = 0;
    vector<string > strs;
    cin >> n;
    
    for(unsigned int i = 0;  i < n; i++){
        string line;
        cin>>line;
        strs.push_back(line);
    }
    cout << "lcp:" << longestCommonPrefix(strs) <<endl;
}