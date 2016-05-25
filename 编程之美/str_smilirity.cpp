#include <string>
#include <iostream>
using namespace std;

// 计算字符串的距离
int CaculateStrDistance(string A, int Abegin, int Aend, string B, int Bbegin, int Bend){
    if(Aend < Abegin)
    {
        if(Bend<Bbegin)
            return 0;
        else
            return (Bend-Bbegin)+1;
    }
    if(Bend < Bbegin){
        return Aend-Abegin;
    }
    if(A[Abegin]==B[Bbegin]){
        return CaculateStrDistance(A, Abegin+1, Aend, B, Bbegin+1, Bend);
    }
    else{
        int t1 = CaculateStrDistance(A, Abegin+2, Aend, B, Bbegin+1, Bend);
        int t2 = CaculateStrDistance(A, Abegin+1, Aend, B, Bbegin+2, Bend);
        int t3 = CaculateStrDistance(A, Abegin+2, Aend, B, Bbegin+2, Bend);
        return min(min(t1,t2),t3)+1;
    }
}

int main(){
    string A = "ABCD";
    string B = "BCDE";
    cout << CaculateStrDistance(A,0,3,B,0,3);
}