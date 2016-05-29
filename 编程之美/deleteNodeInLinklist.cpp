#include <cassert>
#include <iostream>
using namespace std;

struct Node{
    int Data;
    Node *next;
};

//从无头节点中删除一个点。
void deleteNodeInLinklist(Node *node){
    if(node == NULL)
        return;
    assert(node->next !=NULL);
    node->Data = node->next->Data;
    node->next = node->next->next;
    delete node->next;
}

int main(){
    Node *n1 = new Node();
    Node *n2 = new Node();
    Node *n3 = new Node();
    n1->Data = 1;
    n2->Data = 2;
    n3->Data = 3;
    n1->next = n2;
    n2->next = n3;
    deleteNodeInLinklist(n2);
    cout<<n1->next->Data;
    delete n1;
    delete n3;
}