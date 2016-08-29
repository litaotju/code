#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
struct Heap{
    ElementType * elements;
    unsigned int size;
    unsigned int capacity;
};

typedef struct Heap * MaxHeap;

#define MAXELEMENT  1000000
MaxHeap NewMaxHeap(unsigned int capacity){
    MaxHeap H = (MaxHeap)malloc(sizeof(struct Heap));
    H->elements = (ElementType *)malloc(sizeof(ElementType)*capacity+1);
    if( H->elements == NULL){
        printf("Can not malloc so much space. NewMaxHeap(%d)\n", capacity);
        free(H);
        return NULL;
    }
    H->capacity = capacity;
    H->elements[0] = MAXELEMENT;
    H->size = 1;
    return H;
}

void DistroyMaxHeap(MaxHeap H){
    if( H != NULL){
        if(H->elements != NULL){
            free(H->elements);
            H->elements = NULL;
        }
        free(H);
    }
}


int IsFull(MaxHeap H){
    return H->size == H->capacity;
}


void Insert(MaxHeap H, ElementType e){
    if(IsFull(H)){
        printf("isFull\n");
        return;
    }
    int i = ++H->size;
    
    //����丸�׽�С���ͽ�������
    for( ; H->elements[i/2] < e; i /= 2 ){
        H->elements[i] = H->elements[2/i];
    }
    H->elements[i] = e;
}

ElementType DeleteMax(MaxHeap H){
    if(H==NULL || H->size <= 1){
        printf("NULL Heap\n");
        return 0;
    }
    
    unsigned int parent = 1, child;
    ElementType temp, max_element;
    max_element = H->elements[1];
    temp = H->elements[H->size--];    
    for( ; parent*2 <= H->size; parent = child){
        child = parent * 2;
        if(child+1<= H->size && H->elements[child+1] > H->elements[child]){
            child++;
        }
        // temp��child�еĴ�� ��Ҫ��, ˵��������Ķ�Ҫ��
        if( temp > H->elements[child]) break;
        // ����
        else
            H->elements[parent] = H->elements[child];
    }
    H->elements[parent] = temp;
    return max_element;
}

void PrintHeap(MaxHeap H){
    if(H == NULL){
        printf("NULL Heap\n");
        return;
    }
    printf("Heap size: %d, capacity: %d\n", H->size, H->capacity);
    printf("Contents: ");
    
    for(int i=1; i <= H->size; i++){
        printf("%d, ", H->elements[i]);
    }
    printf("\n");
}
int main(){
    MaxHeap H=NULL;
    PrintHeap(H);

    H = NewMaxHeap(10);
    Insert(H, 10);
    Insert(H, 100);
    Insert(H, 100000);
    PrintHeap(H);

    return 0;
}