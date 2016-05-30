/*
 * Source.cpp
 *
 *  Created on: 2016年5月29日
 *      Author: litao
 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

const int KEY_LENGTH = 11;
typedef char ElementType [KEY_LENGTH+1];
typedef int Index;

struct LNode{
    ElementType Data;
    LNode * Next;
    int Count;
};
typedef LNode * PtrToLNode;
typedef PtrToLNode Position;
typedef PtrToLNode List;

struct TblNode{
    int TableSize; //表的大小
    List Heads;    //指向链表头节点的数组
};
typedef TblNode * HashTable;

//判断一个数是不是素数
bool isPrime(int n){
    //assert n >0;
    for(int i = (int)sqrt(n); i>=2 ; i--){
        //被中间的某一个数整除，就不是一个素数
        if( n%i == 0)
            return false;
    }
    return true;
}

const int MAX_TABLESIZE = 100000;
int nextPrime(int N){
    //返回大于N，小于MAX_TABLESIZE的第一个素数
    int p = N%2? N+2:N+1; //p从大于N的第一个奇数开始
    while( p <= MAX_TABLESIZE){
        if(isPrime(p))
            break;
        else
            p += 2;
    }
    return p;
}

//创建散列表
HashTable createTable(int N){
    //散列表的实际条目大小为nextPrime(N)
    HashTable H = (HashTable)malloc(sizeof(TblNode));
    if(H==NULL){
        printf("Can not malloc mem for HashTable\n");
        exit(-1);
    }
    H->TableSize = nextPrime(N);
    H->Heads = (List) malloc(sizeof(LNode)*(H->TableSize));
    if(H->Heads == NULL){
        printf("Can not malloc mem for HashTable-List");
        exit(-1);
    }
    for(int i =0; i< H->TableSize; i++){
        H->Heads[i].Data[0] = '\0'; //空电话号
        H->Heads[i].Count = 0;
        H->Heads[i].Next = NULL;
    }
    return H;
}

Index Hash(int Key, int TableSize){
    return Key % TableSize;
}

//查找元素
Position find(HashTable H, ElementType Key){
    Position p;
    Index pos;
    //计算散列位置
    char * start  = Key+6;
    pos = Hash(atoi(start), H->TableSize);
    p = H->Heads[pos].Next;

    //不到链表的尾部且Data不等于Key
    while( p && strcmp(p->Data, Key)){
        p = p->Next;
    }
    //找到了就返回指向它的指针，否则肯定返回的是NULL
    return p;
}

bool insert(ElementType Key, HashTable H){
    Position P, newCell;
    Index pos;
    P = find(H, Key);
    //如果没有找到，就插入
    if(P == NULL){
        newCell = (LNode *)malloc(sizeof(LNode));
        strcpy(newCell->Data, Key);
        newCell ->Count = 1;
        pos = Hash(atoi(Key+6), H->TableSize);
        newCell->Next = H->Heads[pos].Next;
        H->Heads[pos].Next = newCell;
        return true;
    }
    //已经找到了
    else{
        P->Count ++;
        return false;
    }
}


//扫描输出散列表中的电话狂人
void scanAndOutput(HashTable H){
    int i , MaxCnt=0, Pcnt=0;
    ElementType Phone;
    Phone[0] = '\0';
    Position ptr;
    for(i =0; i<H->TableSize; i++){
        ptr = H->Heads[i].Next;
        while(ptr){
            if(ptr->Count > MaxCnt){
                MaxCnt = ptr->Count;
                strcpy(Phone,ptr->Data);
                Pcnt = 1;
            }
            else if(ptr->Count == MaxCnt){
                Pcnt ++;
                //更新狂人的最小手机号码
                if(strcmp(Phone, ptr->Data) > 0){
                    strcpy(Phone, ptr->Data);
                }
            }
            ptr = ptr->Next;
        }
    }
    printf("%s %d", Phone, MaxCnt);
    if(Pcnt > 1){
        printf(" %d", Pcnt);
    }
    printf("\n");
}

void show(HashTable H){
   LNode * ptr;
   for(int i =0; i<H->TableSize; i++){
	   printf("Table Entry: %d\n", i+1);
		ptr = H->Heads[i].Next;
		while(ptr){
			printf("%s %d\n", ptr->Data, ptr->Count);
			ptr = ptr->Next;
			}
		printf("\n");
	}
}

//释放散列表的内存
// void destoryTable(HashTable H){
//	 if(H==NULL){
//		 return;
//	 }
//	 List heads = H->Heads;
//	 for(int i =0; i< H->TableSize; i++){
//		 LNode * head = &heads[i];
//		 LNode *temp;
//		 while(head){
//			 temp = head->Next;
//			 free(head);
//			 head = temp;
//		 }
//		 free(head);
//	 }
//	 free(H);
// }

int main(){
    ElementType Key;
    HashTable H;
    int N;
    scanf("%d", &N);
    //创建的散列表大小为通话记录的2倍
    H = createTable(N*2);
    for(int i=0; i<N; i++){
        scanf("%s", Key); insert(Key, H);
        scanf("%s", Key); insert(Key, H);
    }
    //show(H);
    scanAndOutput(H);
    //destoryTable(H);
    return 0;
}
