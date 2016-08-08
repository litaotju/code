#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int longestCommonSubstr(const string &a, const string &b){
    if(a.empty() || b.empty())
        return 0;
    vector< vector<int> > dp(a.size(), vector<int>(b.size(), 0) );
    int maxL = 0;
    for(int i=0; i<a.size(); i++){
        dp[i][0] = (a[i]==b[0])?1:0;
        maxL = max(dp[i][0], maxL); 
    }
    for(int j=1; j<b.size(); j++){
        dp[0][j] = a[0]==b[j]?1:0;
        maxL = max(dp[0][j], maxL);
    }
    for(int i=1; i<a.size(); i++){
        for( int j=1; j<b.size(); j++){
            dp[i][j] = a[i]==b[j] ? dp[i-1][j-1]+1 : 0;
            maxL = max(dp[i][j], maxL);
        }
    }
    return maxL;
}

int main(){
    string s, rev;
    while(cin>>s){
        rev = s;
        reverse(rev.begin(), rev.end());
        cout<< longestCommonSubstr(s, rev)<<endl;
    }
}