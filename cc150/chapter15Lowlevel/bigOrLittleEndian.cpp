/*
本程序用于判定电脑主机是 BigEndian 还是LittleEndian
大端(Big-endian):MSB放在低地址，LSB存放在高地址。（大端方式将高位存放在低地址）
小端(Little-endian):MSB存放在高地址，LSB存放在低地址。（小端方式将高位存放在高地址）
*/
#include <iostream>
using namespace std;

#define BIG_ENDIAN 1
#define LITTLE_ENDIAN 0

int bigOrLittleEndian(){
    int a = 0x0001;
    char *byte = (char *)&a;
    //下面这个表达式判断byte[0] 是MSB 还是LSB。
    //为1 就是LSB，也就是说是小端， 为0就是MSB。就是大端
    return (byte[0] ? LITTLE_ENDIAN: BIG_ENDIAN);
}

int main(){
    int endian = bigOrLittleEndian();
    if(endian== BIG_ENDIAN){
        cout<<"BIG Endian"<<endl;
    }else{
        cout<<"Little Endian"<<endl;
    }
}