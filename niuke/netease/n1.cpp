#include <iostream> 
#include <vector> 
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> a(N, 0);
    int sum =0;
    for(int i=0; i<N; i++){
        cin>>a[i];
        sum += a[i];
    }
    //�������������˵���޷��ƶ��õ�
    if( sum % N !=0){
        cout<<"-1"<<endl;
        return 0;
    }
    int avg = sum / N; //һ����һ������
    bool avg_is_even = avg%2==0; //�жϽ������������ż��
    int mov = 0; //�ƶ�����
    
    for(int i=0;i<N; i++){
        //���ĳһ����ţ�� ��ż�Բ�ͬ��ƽ�����϶��޽�
        if(avg_is_even){
            if(a[i]%2!=0) ){
                cout<<"-1"<<endl; 
                return 0;
            }
        }
        if(!avg_is_even){
            if(a[i]%2==0){
                cout<<"-1"<<endl;
                return 0;
            }
        }
        //ֻͳ�ƴ��ڵ���ţ
        if(a[i] > avg){
            //�ƶ�����
            mov += (a[i]-avg)/2;
        }
    }
    cout<<mov<<endl;
    return 0;
}