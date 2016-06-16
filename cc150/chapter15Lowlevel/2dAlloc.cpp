#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

int **my2DAlloc(int rows, int cols){
    // 头部需要 heads个插槽，每一个都指向了一个整数指针
    if(rows <=0 || cols <=0)
        return NULL;
    int heads = rows*sizeof(int *);
    // data的个数等于 rows*cols
    int datas = rows*cols*sizeof(int);
    int **rawptr = (int **)malloc(heads+datas);
    cout<<"ALLO"<<endl;
    
    //但是这个检查好像是不好的。。
    if(rawptr == NULL){
        cout<<"Bad alloc"<<endl;
        return NULL;
    }
    
    int *buf = (int *)(rawptr + rows);
    for(int i =0; i<rows; i++){
        //第i个头指针，指向了第i行
        rawptr[i] = buf;
        buf += cols;
        //全设置为0
        memset(buf,0, cols*sizeof(int));
    }
    return rawptr;
}

int main(){
    int **ptr = my2DAlloc(1000000000,10);
    if(ptr!=NULL)
        cout<<ptr[9][9]<<endl;
    return 0;
}