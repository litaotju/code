#include <stdio.h>


void Print_Factorial(const int N){
if(N<0){
printf("Invalid Input\n");
return;
}
unsigned long long result = 1;
for(int i =1; i<=N; i++)
result *= i;

printf("%lld\n", result);
return; 
}

int main(){
    Print_Factorial(19);
    Print_Factorial(1000);
}