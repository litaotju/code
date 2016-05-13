#include <cstdio>

//使用字面量字符串初始化 字符串指针，相同的字面量的地址相同
//使用字面量字符串初始化 字符数组，  相同的字面量地址是不同的

int main(){
const char str1[] = "abc";
const char str2[] = "abc";
const char *p1 = "abc";
const char *p2 = "abc";
printf("%d %d %d",str1==str2, p1==p2, str1==p1);
return 0;
}