#include <cstdio>
int main(){
    int a = 1;
    int x = 12345678;
    double b = 3.1415926;
    
    //打印一个整数, %.4d, 指的是最少打印4位，不够在高处补0，  
    printf("%d %.4d\n", a, a);
    
    //如果这个整数多余4位，则如下的设置无效，仍然打印出整数的全部位
    printf("%.4d\n", x);
    
    
}