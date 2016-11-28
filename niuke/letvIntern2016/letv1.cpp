#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
    Solution():aranges(0){
        
    }
    int numberOfAranges(vector<string> & canfights){
        set<char> prefix;
        numberOfAranges(canfights, prefix, 0);
        return aranges;
    }
private:
    int aranges;
    void numberOfAranges(vector<string> & canfights, set<char> prefix, int fighter){
        if(fighter == canfights.size()){
            ++aranges; 
            return;
        }
        for(int i = 0; i<canfights[fighter].size(); i++){
            char thisRound = canfights[fighter][i];
            if(prefix.find(thisRound)!= prefix.end()){
                continue;
            }
            prefix.insert(thisRound);
            numberOfAranges(canfights, prefix, fighter+1);
            prefix.erase(thisRound);
        }
    }
};


int main(){
    int N;
    while(cin>>N && N>0){
        vector<string> canfights;
        string fight;
        Solution s;
        for(int i =0; i<N; i++){
            cin>>fight;
            //cout<<fight;
            canfights.push_back(fight);
        }
        //cout<<endl;
        cout<< s.numberOfAranges(canfights)<<endl;
    }
}