#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmpStr(const string & a,const string & b){
    return (a+b) < (b+a);
}


class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> tokens;
        for(auto n : numbers){
            tokens.push_back(to_string(n));
        }
        sort(tokens.begin(), tokens.end(), cmpStr);
        string result;
        for(auto & s: tokens){
            result += s;
        }
        return result;
    }
};
             

int main(){
    vector<int> a {4, 321, 32, 3};
    Solution s;
    cout << s.PrintMinNumber(a)<<endl;
    return 0;
}