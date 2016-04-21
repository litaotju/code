// 1006 
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int main(int argc, char *argv[]){
    int D;
    while(cin>>D && D!=-1){
        if (D==0){
            printf("%.3f\n", 100.0);
        }
        int minMinute = D/6;
        int maxMinute = 60-minMinute;
        int happy_cnt =0;
        for(int i = minMinute; i<= maxMinute; i++){
            for(int j=0; j<=59; j++){
                int angleH = (j*6)%180;
                int angleM = ((int)abs(j-i)*6)%180;
                if( angleH >=D && angleM >= D){
                    happy_cnt++;
                }
            }
        }
        printf("%.3f\n", (happy_cnt/3600.0)*100);
    }
}