#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;


struct ListNode {
    int val;
    ListNode * next;
	ListNode(int value): val(value), next(NULL){};
};

int main(){
    int N;
    while(cin>>N && N>0){
        int value;
        cin>>value;
        ListNode *head = new ListNode(value);
        //≤Â»Î
        for(int i=1; i<N; i++){
            int prev;
            cin>>value>>prev;
            ListNode *pNode = head;
            while(pNode!=NULL && pNode->val != prev){
                pNode = pNode->next;
            }
            assert(pNode!=NULL);
            ListNode * newNode = new ListNode(value);
            newNode->next = pNode->next;
            pNode->next = newNode;
        }
        //…æ≥˝
        cin>>value;
        ListNode *pNode = head;
        bool first = true;
        while(pNode!=NULL){
            if(pNode->val != value){
                if(!first)
                    cout<<" ";
                cout<<pNode->val;
                first = false;
            }
            pNode = pNode->next;
        }
        cout<<endl;
        pNode = head;
        while(pNode!=NULL){
            ListNode * next = pNode->next;
            delete pNode;
            pNode = next;
        }
    }
    return 0;
}