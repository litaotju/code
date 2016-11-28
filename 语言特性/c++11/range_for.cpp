#include <vector>
#include <set>
#include <iostream>
using namespace std;

void testRangeFor(){
    cout<<"testRangeForSet"<<endl;
    vector<int> v = {1,2,3,4,5,6};
    
    //ȡv�е�ÿһ��Ԫ��ֵΪe
    for(auto e:v){
        cout<<e<<endl;
        e *= 2; //������仰�����ܸı� v�е�Ԫ��ֵ
    }
    
    //ȡv�е�ÿһ��Ԫ�� ����Ϊe
    for(auto & element:v){
        cout<<element<<endl;
        element *= 2;
    }
    
    //�۲��������ڶ���ѭ��֮���������ֵ��ÿһ��Ԫ�ض�����2
    for(auto e:v){
        cout<<e<<endl;
    }
}


void testRangeForSet(){
    cout<<"testRangeForSet()"<<endl;
    set<int> seta = {1,9,3,19, 2};
    //��ʱ setû�а���˳���ʼ��������
    //ʹ�������ѭ���õ��� ÿһ��Ԫ����Ȼ�ǰ��մ�С�����˳��ġ�
    for(auto e:seta){
        cout<<e<<endl;
    }
    
    for(auto &e: seta){
        cout<<e<<endl;
        // error , because the key in set can not be alternate
        // so e is readonly
        //e *= 2;
    }
}

int main(){
    testRangeFor();
    testRangeForSet();
}