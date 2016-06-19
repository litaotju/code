#include <set>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    int S;
    while(cin>>S){
        int r = static_cast<int>(ceil(sqrt(S)));
        if(r==0){
            cout<<0<<endl;
            continue;
        }
        int cnt =0;
        set<int> completeSquare;
        completeSquare.insert(0);
        for(int i =1; i<=r; i++){
            completeSquare.insert(i*i);
        }
        for(int x=1; x<=r; x++){
            int y2 = S-x*x;
            if(completeSquare.find(y2)!=completeSquare.end())
                ++cnt;
        }
        cout<<cnt*4<<endl;
    }
}