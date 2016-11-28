#include <stdio.h>
#include <string.h>

//替换字符串中的空格
void ReplaceWP(char s [], int length){
    if(s==NULL || length <= 0){
        return ;
    }
    int originalLength = 0;
    int newLength = 0;
    int numberofBlanck = 0;
    int i = 0;
    
    while( s[i] != '\0' ){
        ++ originalLength ;
        if(s[i] ==' ' ){
            ++ numberofBlanck ;
        }
        ++i;
    }
    
    newLength = originalLength + numberofBlanck * 2;
    
    if(newLength > length)
        return;
    
    int originalIndex = originalLength;
    int newIndex = newLength;
    
    while(originalIndex >=0 && newIndex > originalIndex){
        
        if( s[originalIndex] != ' '){
            s[newIndex--] = s[originalIndex--];
        }
        else{
            --originalIndex;
            s[newIndex--] = '0';
            s[newIndex--] = '2';
            s[newIndex--] = '0';
        }
    }
}

int main(int argc, char *argv []){
    
    char  s[100];
    strcpy(s, argv[1]);
    printf("%s\n", s);
    
    ReplaceWP(s, 100);
    printf("%s\n", s);
    
    return 0;
}