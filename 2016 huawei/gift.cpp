#include <iostream>
#include <string>
#include <stack>
#include <cstdio>
using namespace std;

int compute_index(string cur_case){
    stack<char> boxes;
    int ret = 0; 
    for(unsigned int i=0; i< cur_case.size(); i++){
        if( !boxes.empty() ){
            if(boxes.top() == 'A'){
                boxes.pop();
                break;
            }
            if(boxes.top() == '(' && cur_case[i] ==')'){
                boxes.pop();
            }else{
                boxes.push(cur_case[i]);
            }
        }else{
            boxes.push(cur_case[i]);
        }
    }
    while(!boxes.empty()){
        boxes.pop();
        ret++;
    }
    return ret;
}

int main(){
    string cur_case;   
    cin>>cur_case;
    while( !cur_case.empty() ){
		if (cur_case.length() > 1){
			cout << compute_index(cur_case) << endl;
			cur_case.clear();
			cin >> cur_case;
		}
    }
    return 0;
}