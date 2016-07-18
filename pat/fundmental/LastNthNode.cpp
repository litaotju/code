#include <cassert>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
struct ListNode {
    ListNode * next;
    int value;
    ListNode(int _value): value(_value){
        next = NULL;
    }
};

class LinkedList{

    ListNode * head;
    int Length;

public:
    LinkedList(){
        head = NULL;
        Length = 0;
    }
    
    LinkedList & insertFront(int value){
        ListNode * temp = new ListNode(value);
        temp->next = head;
        head = temp;
        ++Length;
       return *this;
       
    }
    
    ~LinkedList(){
        while(head != NULL){
            -- Length;
            ListNode * temp = head;
            head = temp->next;
            delete temp;
        }
        assert(Length == 0);
    }
    
ListNode * findNthLast(int N){
    if(head == NULL || N <1 ){
        return NULL;
    }
    ListNode * slow = head, * fast = head;
    for(int i=0; i<N; i++){
        if(fast == NULL)
            return NULL;
        fast = fast->next;
    }
    while(fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
    }
    
    int getLength() const{
        return Length;
    }
    ListNode * getHead() const{
        return head;
    }
};


ListNode * addList(ListNode *L1, ListNode *L2, int cin){
    if(NULL == L1 && NULL == L2){
        if(cin==0)
            return NULL;
        else{
            ListNode * tail = new ListNode(cin);
            return tail;
        }
    }
    
    int sum = cin;
    if(L1 != NULL){
        sum += L1->value;
    }
    if(L2 != NULL){
        sum += L2->value;
    }
    ListNode *head = new ListNode(sum % 10);
    head ->next = addList( L1 == NULL? NULL:L1->next,
                            L2 == NULL? NULL: L2->next,
                            sum >= 10 ? 1:0
            );
    return head;
}

ListNode * addList(ListNode * L1, ListNode * L2){
    return addList(L1, L2, 0);
}

string toString(ListNode * head){
        if (head == NULL){
            string ret;
            return ret;
        }
        string result;
        ListNode *temp = head;
        while(temp != NULL){
            result += static_cast<char>('0'+temp->value);
            temp = temp ->next;
        }
        reverse(result.begin(), result.end());
        return result;
}
    

void TestFindNthLast(){
    LinkedList l;
    assert(l.findNthLast(0) == NULL);
    
    l.insertFront(1);
    assert(l.findNthLast(1) ->value == 1);
    assert(l.findNthLast(2) == NULL);
    
    l.insertFront(2);
    assert(l.findNthLast(2)->value == 2);
    
    l.insertFront(3).insertFront(4).insertFront(5);
    
    for(int i = 1; i<=5; i++){
        assert(l.findNthLast(i)->value == i);
    }
    cout<< toString(l.getHead())<<endl;
   
}

void TestAddList(){
    // Test For add List
    LinkedList l1;
    l1.insertFront(1).insertFront(2);
    cout<< toString(l1.getHead())<<endl;
    
    LinkedList l2;
    l2.insertFront(8).insertFront(8);
    
    cout<<toString(l2.getHead())<<endl;
    string result = toString(addList(l1.getHead(), l2.getHead()));
    cout << result<<endl;
    assert( result== "100");
}


int main(){
    TestFindNthLast();
    TestAddList();
}