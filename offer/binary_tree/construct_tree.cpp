#include <iostream>
#include "treenode.h"
#include <vector>
#include <cstdio>
#include <stdexcept>
using namespace std;

TreeNode<int> * construct_tree(const vector<int> & preorder, int start, int end,
            const vector<int> & inorder, int istart, int iend);

TreeNode<int> * construct_tree(const vector<int> & preorder, const vector<int> & inorder ){
    if( preorder.empty() || inorder.empty() || preorder.size()!=inorder.size())
        return nullptr;
    return construct_tree(preorder, 0, preorder.size()-1, inorder , 0, inorder.size()-1);
}

TreeNode<int> * construct_tree(const vector<int> & preorder, int start, int end,
            const vector<int> & inorder, int istart, int iend)
{
    // printf("preorder: %d %d, inorder: %d %d\n", start, end, istart, iend);
    TreeNode<int> * root = new TreeNode<int>();
    root->val = preorder[start];
    root->left = root->right = nullptr;
    if(start==end){
        if(istart == iend)
            return root;
        else{
            //printf("preorder: %d %d, inorder: %d %d\n", start, end, istart, iend);
            throw logic_error("Invalid input, the inorder and the preorder is not same length");
        }
    }
    int indexIn = istart;
    while( indexIn <= iend && inorder[indexIn]!=preorder[start])
        indexIn++;

    if(indexIn > iend)
        throw logic_error("Invalid input, does not find root in inorder seq");
    
    int leftLen = indexIn - istart, rightLen = iend-indexIn;
    if(leftLen > 0)
        root->left = construct_tree(preorder, start+1, start+leftLen,
                inorder, istart, indexIn-1);

    if( rightLen > 0)
        root->right = construct_tree(preorder, start+leftLen+1, end,
                inorder, indexIn+1, iend);
    return root;
}

void PrintPostOrder( TreeNode<int> *root ){
    if(root==nullptr)
        return;
    PrintPostOrder(root->left);
    PrintPostOrder(root->right);
    printf("%d\n", root->val);
}

int main(){
    vector<int> a {1, 2, 3, 4, 5};
    vector<int> b {2, 3, 1, 4, 5};
    TreeNode<int> * root  = construct_tree(a, b);
    cout<<"root->left "<< root->left->val<<endl;
    cout<<"root->right "<< root->right->val<<endl;
    PrintPostOrder(root);
    return 0;
}