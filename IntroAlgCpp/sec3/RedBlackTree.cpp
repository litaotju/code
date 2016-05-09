#include <iostream>
using namespace std;

typedef int Data;

enum Color{
    red,
    black
};

class Node{
public:
    Color color;
    Data key;
private:
    Node * left;
    Node * right;
    Node * parent;
    friend RedBlackTree<Node>;
public:
    Node(){
        color = black;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
    friend ostream & operator << (ostream &out, Node & node){
		out<< node.key;
		return out;
	}
};

template <class Node>
class RedBlackTree{
public:
    Node * root;
    Node * nil;
    RedBlackTree(){
        nil = new Node();
    }
    RedBlackTree(Node *node){
        root = node;
        nil = new Node();
    }

    ~RedBlackTree(){
        delete nil;
    }
    
    RedBlackTree & insert(Node *){
    }
        
    RedBlackTree & leftRotate(Node *x){
        Node * y = x->right;
        //把 Y的左边 挂到x上面
        x->right = y->left;
        if( y->left != this->nil){
            y->left->parent = x;
        }
        //y上移
        y->parent = x->parent;
        if( x->parent == this->nil){
            root = y;
        }else if( x == x->parent->left){
            x->parent->left = y;
        }else{
            x->parent->right = y;
        }
        //x y 相连接
        y->left = x;
        x->parent = y;
        return *this;
    }
    
    RedBlackTree & rightRotate(Node *y){
        Node *x = y->left;
        //把 x的右子树，挂到y的左边
        y->left = x->right;
        if( x->right != this->nil){
            x->right->parent = y;
        }
        
        //提升x
        x->parent = y->parent;
        if(y->parent == this->nil){
            root = x;
        }else if( y->parent->left == y){
            y->parent->left = x;
        }else{
            y->parent->right = x;
        }
        //x y 相连接
        x->right = y;
        y->parent = x;
        return *this;
    }
};

int main(){
    RedBlackTree<int> tree;
}