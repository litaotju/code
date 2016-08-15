#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 10000;
const int max_child = 26;
struct Node {
    Node *ch[26];
    int num;
};

Node a[N], *root;

int p=0;
Node * newNode(){
    memset(a[p].ch, 0, sizeof(a[p].ch));
    a[p].num = 0;
    return &a[p++];
}


void insert(char *s){
    Node *cur = root;
    cur->num ++;
    while(*s!='\0'){
        int t = *(s++)-'a';
        if(cur->ch[t] == NULL){
            cur->ch[t] = newNode();
        }
        cur = cur->ch[t];
        cur->num ++;
    }
}


int getans(char *s){
    Node * cur = root;
    while(*s != '\0'){
        int t = *(s++)-'a';
        if(cur->ch[t] == NULL) return 0;
        cur = cur->ch[t];
    }
    return cur->num;
}


int main(){
    char s[11];
    root = newNode();
    get(s);
    while(s[0] != '\0'){
        insert(s);
        gets(s);
    }
    while(scanf("%s", s) != EOF){
        printf("%d\n", getans(s));
    }
    return 0;
}
