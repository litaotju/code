#include <string>
#include <iostream>
using namespace std;
/*�ڼ������������Ӧ����ȵĸ���ֱֵ���� == �ţ����صĽ���ǲ�ȷ����
ȡ���ڼ������ʶ����������ֵ�ľ��ȡ����� ����ıȽϲ�Ӧ�������� ==�š�
��Ȼ��Щ��������ķ���ֵ�����ǵ�Ԥ����ͬ
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