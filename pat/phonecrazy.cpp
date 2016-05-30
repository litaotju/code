/*
 * Source.cpp
 *
 *  Created on: 2016��5��29��
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
    int TableSize; //��Ĵ�С
    List Heads;    //ָ������ͷ�ڵ������
};
typedef TblNode * HashTable;

//�ж�һ�����ǲ�������
bool isPrime(int n){
    //assert n >0;
    for(int i = (int)sqrt(n); i>=2 ; i--){
        //���м��ĳһ�����������Ͳ���һ������
        if( n%i == 0)
            return false;
    }
    return true;
}

const int MAX_TABLESIZE = 100000;
int nextPrime(int N){
    //���ش���N��С��MAX_TABLESIZE�ĵ�һ������
    int p = N%2? N+2:N+1; //p�Ӵ���N�ĵ�һ��������ʼ
    while( p <= MAX_TABLESIZE){
        if(isPrime(p))
            break;
        else
            p += 2;
    }
    return p;
}

//����ɢ�б�
HashTable createTable(int N){
    //ɢ�б��ʵ����Ŀ��СΪnextPrime(N)
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
        H->Heads[i].Data[0] = '\0'; //�յ绰��
        H->Heads[i].Count = 0;
        H->Heads[i].Next = NULL;
    }
    return H;
}

Index Hash(int Key, int TableSize){
    return Key % TableSize;
}

//����Ԫ��
Position find(HashTable H, ElementType Key){
    Position p;
    Index pos;
    //����ɢ��λ��
    char * start  = Key+6;
    pos = Hash(atoi(start), H->TableSize);
    p = H->Heads[pos].Next;

    //���������β����Data������Key
    while( p && strcmp(p->Data, Key)){
        p = p->Next;
    }
    //�ҵ��˾ͷ���ָ������ָ�룬����϶����ص���NULL
    return p;
}

bool insert(ElementType Key, HashTable H){
    Position P, newCell;
    Index pos;
    P = find(H, Key);
    //���û���ҵ����Ͳ���
    if(P == NULL){
        newCell = (LNode *)malloc(sizeof(LNode));
        strcpy(newCell->Data, Key);
        newCell ->Count = 1;
        pos = Hash(atoi(Key+6), H->TableSize);
        newCell->Next = H->Heads[pos].Next;
        H->Heads[pos].Next = newCell;
        return true;
    }
    //�Ѿ��ҵ���
    else{
        P->Count ++;
        return false;
    }
}


//ɨ�����ɢ�б��еĵ绰����
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
                //���¿��˵���С�ֻ�����
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

//�ͷ�ɢ�б���ڴ�
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
    //������ɢ�б��СΪͨ����¼��2��
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
