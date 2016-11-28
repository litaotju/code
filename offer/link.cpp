#include <stdio.h>
#include <stack>

struct ListNode{
	int value;
	ListNode * p_next;	
};

//向链表末尾添加元素
void AddtoTail(ListNode **p_head, int value){
	ListNode *node = new ListNode();
	node->value = value;
	node->p_next = NULL;
	
	if(*p_head == NULL){
	    *p_head = node;
	}
	else{
	    ListNode *p_node = *p_head;
	    while(p_node->p_next !=NULL){
		p_node = p_node->p_next;
		}
	    p_node->p_next = node;
	}	
}

//从头到尾遍历链表并打印
void Traseverse(ListNode *p_head){
    if(p_head == NULL)
        return;
    ListNode * p_node = p_head;
    while(p_node -> p_next != NULL){
        printf("->%d", p_node->value);
        p_node = p_node -> p_next;
    }
    printf("->%d\n",  p_node->value);
}

//删除链表中的节点（根据值。删除第一次出现的值）
void RemoveNode(ListNode **p_head, int value){
	if (p_head == NULL || *p_head== NULL){
		return;
	}
	ListNode *toBeDeleted = NULL;
	
	//如果链表头要删除
	if( (*p_head)->value == value){
		toBeDeleted = *p_head;
		*p_head = (*p_head)->p_next;
	}
	//非链表头
	else{
		ListNode * p_node = *p_head;
		//一直向前移动，直到下一个元素是要删除的元素，或者到链表的倒数第一个元素
		while(p_node->p_next !=NULL && p_node->p_next->value != value)
			p_node = p_node ->p_next;
		
		//确实找到了要删除的元素，记录下来要删除的值。
		if(p_node ->p_next !=NULL && p_node->p_next->value== value){
			toBeDeleted = p_node->p_next;
			p_node->p_next = p_node->p_next->p_next;
		}
	}
	if(toBeDeleted !=NULL){
		delete toBeDeleted;
		toBeDeleted = NULL;
	}
}

//面试题5

void PrintLinkListReversely(ListNode * p_head){
	std::stack<ListNode * > nodes;
	ListNode * p_node = p_head;
	while(p_node !=NULL){
		nodes.push(p_node);
		p_node = p_node->p_next;
	}
	while( !nodes.empty()){
		printf("->%d", nodes.top()->value);
		nodes.pop();
	}
}
void PrintLinkListReversely_R(ListNode *p_head){
	if(p_head != NULL){
		if(p_head->p_next != NULL){
			PrintLinkListReversely_R(p_head->p_next);
		}
		printf("->%d", p_head->value);
	}
}
int main(){
    int a [] = {1, 34, 5, 67, 34};
    int i = 0;
	
	ListNode ** head;
	*head = NULL;
	for(i = 0; i<5; i++){
        AddtoTail(head, a[i]);
        printf("Step %d\n", i);
        Traseverse(*head);
    }
	
	//移除特定元素34的第一个出现的节点
	RemoveNode(head, 34);
	Traseverse(*head);
	
	//反转打印链表
	printf("The reverse is:\n");
	PrintLinkListReversely(*head);
	
	//递归方法反转输出链表
	PrintLinkListReversely_R(*head);
}