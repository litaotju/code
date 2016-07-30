#include <vector>
#include <string>
#include <iostream>
using namespace std;

class GrayCode {
public:
    vector<string> getGray(int n) {
        vector<string> result;
        if(n<=0)
            return result;
        result.push_back(string("0"));
        result.push_back(string("1"));
        return getGray(result, n-1);
    }
    
    vector<string> getGray(vector<string> & result, int needBits){
        if(0==needBits)
            return result;
        vector<string> oneBitMore;
        bool isEvenRound = false;
        for(int i=0; i<result.size(); i++){
           	if(!isEvenRound){
            	oneBitMore.push_back( result[i] + "0" );
        		oneBitMore.push_back( result[i] + "1" );
            }else{
                oneBitMore.push_back( result[i] + "1" );
                oneBitMore.push_back( result[i] + "0" );
            }
            isEvenRound = !isEvenRound;
        }
        return getGray(oneBitMore, needBits-1);
    }
};

int main(){
    
    GrayCode g;;
    for(int i =1; i<=3; i++){
        vector<string> gy = g.getGray(i);
        for(auto &e: gy)
            cout<<e<<endl;
    }
}