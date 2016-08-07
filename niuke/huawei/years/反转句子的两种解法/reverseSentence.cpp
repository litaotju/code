#include <cstdio>
#include <cstring>

const int max_length = 1000;
int main(){
    char str[max_length];
    memset(str, 0, sizeof(str));
    gets(str);
    int i=0, j=0;
    int length = 0;
    //找到结尾
    while( j<max_length && str[j++]!='\0');
    j-=2;
    length = j;
    
    //逐个字符反转
    while( i<j){
        char temp;
        temp = str[i];
        str[i++] = str[j];
        str[j--] = temp;
    }
    
    //反转每一个单词
    int cur=0, w_start, w_end;
    while( cur<=length ){
        w_start = w_end = cur;    
        //直到空字符
        while(w_end<=length && str[w_end++]!=' ')
        //下一个单词的开始
        cur = w_end+1;
        
        //这个单词的末尾
        if( cur<= w_end)
            w_end -= 2;
        else
            w_end -=1;
        
        while(w_start < w_end){
            char temp;
            temp = str[w_start];
            str[w_start++] = str[w_end];
            str[w_end--] = temp;
        }
    }
    printf("%s", str);
}