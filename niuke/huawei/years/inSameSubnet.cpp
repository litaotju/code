#include <iostream>
#include <string>
// #include <bitset>
using namespace std;

int C_ERR = 0; 

unsigned int dotToInteger(const string & input){
    if(input.empty())
        return 0;
    unsigned int result = 0;
    unsigned int  sec = 0;
    int start =0, end = 0, index = 0;
    while(start < input.size()){
        while( end < input.size() && input[end]!='.'){
            if(!(input[end] <='9' && input[end] >='0')){
                C_ERR = -1;
                return 0;
            }
            end++;
        }
        sec = stoi(input.substr(start, end-start));
        if(sec<0 || sec>255){
            C_ERR = -1;
            return 0;
        }
        result = result | (sec << (32-(++index)*8));
        start = end+1;
        end = start;
    }
    return result;
}

int inSameSubnet(const string & mask, const string & ip1, const string & ip2){
    // bitset<32> maskBits = bitset<32>( dotToInteger(mask) );
    // bitset<32> ip1Bits = bitset<32>(dotToInteger(ip1));
    // bitset<32> ip2Bits = bitset<32>(dotToInteger(ip2));
    C_ERR = 0;
    unsigned int maskBits = dotToInteger(mask), ip1Bits = dotToInteger(ip1), ip2Bits = dotToInteger(ip2);
    if(C_ERR == -1)
        return 1;
    return (maskBits & ip1Bits) == (maskBits & ip2Bits) ? 0: 2;
}

int main(){
    string mask, ip1, ip2;
    while(cin>>mask>>ip1>>ip2){
        cout<<inSameSubnet(mask, ip1, ip2)<<endl;
    }
    return 0;
}