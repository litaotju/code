#include <iostream>
#include "treenode.h"
#include <stack>
using namespace std;

// TODO:
template<class T>
void postoder_iter(TreeNode<T> *root){
    if(root==nullptr)
        return;
    stack<TreeNode<T> *> visit;
    TreeNode<T> * cur = root;
    while(cur !=nullptr){
        visit.push(cur);
        cur = cur->next;
    }
    while(!visit.empty()){
        cur = visit.top();
        if(cur->right == nullptr){
            cout<<cur->val<<endl;
            visit.pop();
        }

    }
}