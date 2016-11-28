#include <vector>
#include <iostream>
#include <set>
using namespace std;

int numberofCombi(const vector<int> & codes, const vector<int> & num){
    if(codes.empty())
        return 1;
    set<int> has;
    has.insert(0);
    for(int i=0; i < codes.size(); i++){
        set<int> temp;
        for(int j=1; j <= num[i]; j++){
            int weight =0;
            for(auto e: has){
                weight = e + codes[i]*j;
                if(has.find(weight) == has.end() && temp.find(weight)==temp.end()){
                    temp.insert(weight);
                }
            }
        }
        for( auto e: temp ){
            has.insert(e);
        }
    }
    return has.size();
}

int main(){
    int N;
    vector<int> code;
    vector<int> num;
    while(cin>>N){
        int temp;
        for(int i=0; i<N; i++){
            cin>>temp;
            code.push_back(temp);
        }
        for(int i=0; i<N; i++){
            cin>>temp;
            num.push_back(temp);
        }
        cout<<numberofCombi(code, num)<<endl;
    }
}