#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned int getNum(unsigned int num){
	unsigned int result =0 ;
	unsigned int left = num;
	while(left){
		if( left <= 1){
			left = 0;
		}else if( left <= 3){
			left =0;
			result += 1;
		}else{
			result +=  left / 3;
			left = left%3 + left/3;
		}
	}
	return result;
}

void printNum(unsigned int i){
	cout << getNum(i) <<endl;
}

int main(){
    vector<unsigned int> inputs;
    unsigned int tmp;
    while(cin >> tmp){
        if(tmp != 0){
            inputs.push_back(tmp);
        }else{
            break;
        }
    } 	
	for_each( inputs.begin(), inputs.end(), printNum);
}