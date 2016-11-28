#include<iostream>
using namespace std;
typedef struct
{
char flag[3];
short value;
} sampleStruct;
union
{
char flag[3];
short value;
} sampleUnion;


int main()//主函数
{
    cout<< sizeof(sampleStruct);
    cout << sizeof(sampleUnion);
}