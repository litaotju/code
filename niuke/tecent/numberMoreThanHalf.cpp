#include <vector>
#include <unordered_map>
#include <cassert>
#include <iostream>
using namespace std;

class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        if(gifts.empty())
            return 0;
        int half = gifts.size()/2;
        unordered_map<int, int> freq;
        for(auto e : gifts)
            freq[e] += 1;
        for(auto &p: freq){
            cout<< p.first <<" "<<p.second<<endl;
            if(p.second >= half)
                return p.first;
        }
        return 0;
    }
};


void test(){
    vector<int> gifts = {1,2,3,3};
    Gift g;
    assert( g.getValue(gifts, 4) == 3);
}

int main(){
    test();
}