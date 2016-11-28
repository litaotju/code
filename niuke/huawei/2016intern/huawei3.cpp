#include <iostream>
#include <assert.h>
using namespace std;

#define MAX_LINE_SIZE 100

inline int getDigit( char & c){
	if( c >= '0' && c <='9'){
		return static_cast<int>(c - '0');
	}else if ( c >= 'A' && c<='F' ){
		return static_cast<int>( 10 + c - 'A');
	}else if( c >= 'a' && c<='f'){
		return static_cast<int>( 10 + c-'a');
	}
	return -1;
}

int getDec(string s){
	assert( s.size() > 2 );
	assert( s[0] == '0');
	assert( s[1] == 'x'|| s[1] == 'X');
	int index = 2;
	int result = 0;
	while( index < s.size()){
		int digit = getDigit(s[index] );
		if(digit != -1){
			result = result * 16+ digit;
		}else{
			cout<<"Bad char" << s[index] << endl;
			break;
		}
		index ++;
	}
	return result;
}

int main(){
	char cs[MAX_LINE_SIZE];
	cin.getline(cs, MAX_LINE_SIZE);
	string s(cs);
	cout << getDec(s) << endl;
}