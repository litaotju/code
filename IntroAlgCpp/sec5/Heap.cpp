/*
 * Heap.cpp
 *
 *  Created on: 2016年5月30日
 *      Author: litao
 * 本源代码演示了二项堆的数据结构和基本操作
 */
 
 
#include <cstdlib>
#include <cassert>
#include <cstdio>

typedef int ElementType ;
//堆的最大值，作为守护者
const ElementType MaxData = 10000000;
struct HNode{
	ElementType * Data;
	int Capacity;
	int Size;
};
typedef HNode * Heap;
typedef Heap MaxHeap;
typedef Heap MinHeap;

Heap CreateHeap(int MaxSize){
	Heap H = (Heap)malloc(sizeof(HNode));
	if(H == NULL){
		printf("Cannot malloc mem for HNode\n");
		return H;
	}
	H->Data = (ElementType *)malloc(sizeof(ElementType)*(MaxSize+1));
	if(H ->Data == NULL){
		free(H);
		return NULL;
	}
	H ->Size = 0;
	H ->Capacity = MaxSize;
	H ->Data[0] = MaxData;
	return H;
}

bool IsFull(Heap H){
	return H->Size == H->Capacity;
}

bool IsEmpty(Heap H){
	return H->Size == 0;
}

bool Insert(Heap H, ElementType Item){
	//
	assert(Item < MaxData);
	if(IsFull(H)){
		printf("最大堆已满");
		return false;
	}
	int X = ++H->Size; //指向尾部
	for(; H->Data[X/2] < Item; X/=2){
		//一直到 X/2 = 0,此时第一个数是最大值，所以一定跳出循环
		H->Data[X] = H->Data[X/2]; //往上挪
	}
	H ->Data[X] = Item;
	return true;
}


const int Error = -1;
ElementType DeleteMax(Heap H){
	if( IsEmpty(H)){
		printf("最大堆已空\n");
		return Error;
	}
	ElementType MaxItem = H->Data[1]; //这是要返回的最大值
	//想办法保持堆的属性不变
	ElementType X = H->Data[H->Size--];//最后一个元素
	int parent, child;
	for( parent = 1; parent*2 <= H->Size; parent = child){
		child  = parent *2; //左儿子
		//找到较大的儿子
		if( child != H->Size && H->Data[child]< H->Data[child+1])
			child ++;
		if(X >= H->Data[child]) break;
		//提升较大的儿子
		H->Data[parent] = H->Data[child];
	}
	H->Data[parent] = X;
	return MaxItem;
}

/*-------------------------------
 * 建造最大堆
 */

//将以p为父节点的树狗造成最大堆

void PearcDown(Heap H, int p){
	//assert(p <= H->Size)
	int parent, child;
	ElementType X;
	X = H->Data[p]; //存放根节点的值
	for(parent =p; parent *2 <= H->Size; parent= child){
		child = parent *2; //左儿子
		//获取儿子中的最大值
		if(child != H->Size && H->Data[child] < H->Data[child+1])
			child ++;
		if(X >= H->Data[child]) break;
		H->Data[parent] = H->Data[child];
	}
	H->Data[parent] = X;
}

void BuildHeap(MaxHeap H){
	for(int i = H->Size/2; i >= 1; i--)
		PearcDown(H, i);
}

void Show(Heap H){
	if(IsEmpty(H)){
		printf("Heap is　Empty\n");
		return;
	}

	for(int i = 1; i <= H->Size; i++){
		printf("%d", H->Data[i]);
		if(i!= H->Size)
			printf(" ->");
	}
	printf("\n");
}

int main(){
	int N;
	scanf("%d", &N);
	Heap H = CreateHeap(N);
	ElementType * data = (ElementType *)malloc(sizeof(ElementType)*N);
	for(int i = 0; i<N; i++){
		scanf("%d", data+i);
		Insert(H, data[i]);
		Show(H);
	}
	printf("Insert Finished\n");
	int M = H->Size;
	while(!IsEmpty(H)){
		printf("Max is： %d   ", DeleteMax(H));
		printf("Heap is:");
		Show(H);
	}
}