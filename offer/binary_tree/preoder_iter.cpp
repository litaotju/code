#include <iostream>
#include "treenode.h"
#include <stack>
using namespace std;

//前序循环遍历
template<class T>
void inorder_iter(TreeNode<T> * root){
    if(root==nullptr)
        return;
    stack< TreeNode<T> *> visit;
    visit.push(root);

    TreeNode<T> * cur = nullptr;
    while(!visit.empty()){
        cur = visit.top();
        visit.pop();
        cout<<cur->val<<endl;
        if( cur->right != nullptr)
            visit.push(cur->right);
        if(cur->left != nullptr)
            visit.push(cur->left);
    }
}


int main(){
    TreeNode<int> *root = build_tree<int>();
    inorder_iter<int>(root);
}