#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode * next;
};


void printLinkListRevert(ListNode *head){
    if(head==NULL)
        return;
    printLinkListRevert(head->next);
    cout<<head->val<<endl;
}

int main(){
    ListNode a = {3, NULL}, b = {2, &a}, c = {1, &b};
    printLinkListRevert(&c);
    return 0;
}