#include <cstdio>
#include <cstring>
#include <cstdlib>

void swap(char *a, char *b){
    if(a==b)
        return;
    char temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(char *str, int len, int start){
    if(start==len){
        printf("%s\n", str);
        return;
    }
    for(int j=start; j<len; j++){
        swap(str+start, str+j);
        permutation(str, len, start+1);
        swap(str+start, str+j);
    }
}

void permutation(char *str, int len){
    if(str==NULL || len==0){
        return;
    }
    permutation(str, len, 0);
}



int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Usage: prog string");
        exit(1);
    }
    char * str = argv[1];
    int len = strlen(argv[1]);
    permutation(str, len);
    return 0;
}