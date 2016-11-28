#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmp(const void *a, const void *b){
    return *(char *)a > *(char *)b;
}

void sort(char *line, int len){
    qsort(line, len, sizeof(char), cmp);
    return;
}

int main(){
    char line[1025];
    memset(line, 0, 1025);
    while(scanf("%s", line)!=EOF){
        sort(line, strlen(line));
        printf("%s\n", line);
        memset(line, 0, strlen(line)+1);
    }
}