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
    //如果不能整除，说明无法移动得到
    if( sum % N !=0){
        cout<<"-1"<<endl;
        return 0;
    }
    int avg = sum / N; //一定是一个整数
    bool avg_is_even = avg%2==0; //判断结果是奇数还是偶数
    int mov = 0; //移动次数
    
    for(int i=0;i<N; i++){
        //如果某一个奶牛的 奇偶性不同于平均，肯定无解
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
        //只统计大于的奶牛
        if(a[i] > avg){
            //移动次数
            mov += (a[i]-avg)/2;
        }
    }
    cout<<mov<<endl;
    return 0;
}