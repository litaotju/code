#include <iostream>

//Ϊ��˵���ڲ�ͬ��ϵͳ�µ�sizeof�Ĵ�С��
//
using namespace std;

int main(int argc, char * argv[]){
	int iA[5];
	int *p_iA;
	
	cout<<"size of int [5]"<<sizeof iA<<endl;
	cout<<"size of int *"<<sizeof p_iA<<endl;
	cout<<"sizeof int "<<sizeof(int)<<endl;
	cout<<"sizeof short "<<sizeof(short)<<endl;
	cout<<"sizeof long " <<sizeof(long)<<endl;
	cout<<"sizeof float" <<sizeof(float)<<endl;
	cout<<"sizeof double" <<sizeof(double)<<endl;
	
}