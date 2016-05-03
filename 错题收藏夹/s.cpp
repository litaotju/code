#include <string>
#include <iostream>
using namespace std;
/*在计算机总两个本应该相等的浮点值直接用 == 号，返回的结果是不确定的
取决于计算机标识这俩个浮点值的精度。所以 浮点的比较不应该总是用 ==号。
虽然有些情况下它的返回值与我们的预期相同
*/
int main(){
	string a;
	cin>>a;
	cout<<endl;
	if( "string" == a){
		cout<<a<<endl;
	}else{
		cout<<"Dostnot match 'string' "<<endl;
	}
	double varDouble;
	bool varBin = false;
	int varInt = 1;
	if(false == varBin){
		cout<<"boolean can be equal"<<endl;
	}
	cin>>a;
	varDouble = stod(a);
	if( 0.02 == varDouble){
		cout<<"Double can be =="<<endl;
	}
	if( 1 == varInt){
		cout<<"Int can be =="<<endl;
	}
	
}