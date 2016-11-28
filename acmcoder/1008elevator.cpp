#include <iostream>
using namespace std;

int main(int argc, char*argv[]){
    
    int N;
    while(cin>>N && N>0){
        int *array = new int[N];
        for(int i=0; i<N; i++){
            cin>> array[i];
        }
        bool isUp = true;
        int lastFloor = 0;
        int time = 0;
        for(int i=0; i<N; i++){
            isUp = (array[i]-lastFloor > 0);
            if(isUp)
                time += (array[i]-lastFloor)*6+5;
            else
                time += (lastFloor-array[i])*4+5;
            lastFloor =array[i];
        }
        cout<<time<<endl;
        delete [] array;
    }
}