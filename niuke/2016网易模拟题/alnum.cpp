#include <cstdio>
int main(){
    int n, s, L;
    scanf("%d %d %d", &n, &s, &L);
    int X = (L+1)/(s+1);
    while(0 == X%13)
        X -= 1;
    int alnumNum = n/X + ((n%X==0)? 0:1);
    printf("%d", alnumNum);
    return 0;
}