#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

typedef int NodeData_t;

struct BiNode{
	NodeData_t data;
	BiNode * left;
	BiNode * right;
	BiNode * parent;
	BiNode(NodeData_t data){
		this->data = data;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
	friend ostream & operator << (ostream &out, BiNode & node){
		out<< node.data;
		return out;
	}
};


template<class Node> 
class BiSearchTree {
public:
	Node * root;
	BiSearchTree(Node * root){
		assert(root!= NULL);
		this->root = root;
	}
	//�������
	void inorderTreeWalk(){
		_inorderTreeWalk(root);
	}
	
	//TODO:�ǵݹ�汾���������
	void inorderTreeWalk_i(Node * x){ 
		stack<Node *> node_stack;
	}
	
	//�ݹ�汾������
	Node & search( NodeData_t keyword){
		return _search(root, keyword);
	}
	
	//�����汾������
	Node & search_i(NodeData_t keyword){
		Node *x = root;
		while( x != NULL && x->data != keyword){
			if( keyword < x->data){
				x = x->left;
			}else{
				x = x->right;
			}
		}
		return *x;
	}
	
	Node & minimum(){
		Node *x = root;
		while(x->left != NULL){
			x = x->left;
		}
		return *x;
	}
	
	Node & minimum_r(){
		return minimum_r(root);
	}
	
	Node & minimum_r( Node * start){
		if(start ->left == NULL){
			return *start;
		}
		return minimum_r(start ->left);
	}
	
	Node & maximum(){
		Node *x = root;
		while( x->right != NULL){
			x = x->right;
		}
		return *x;
	}
	
	Node & maximum_r(){
		return maximum_r(root);
	}
	Node & maximum_r(Node * start){
		if( start ->right == NULL){
			return *start;
		}else{
			return maximum_r(start->right);
		}
	}
	
	//TODO:����������ĺ�̽�����
	Node & successor(Node * node){
		assert(node != NULL);
		if(node->right != NULL){
			return this->minimum_r(node->right);
		}
		Node * parent = node->parent;
		while( parent != NULL && node == parent->right){
			node = parent;
			parent  = parent->parent;
		}
		return *parent;
	}
	
private:
	//������������Ӷ�ΪO(n)
	void _inorderTreeWalk(Node * x){
		if( x == NULL) return;
		_inorderTreeWalk(x->left);
		cout<< *x <<", ";
		_inorderTreeWalk(x->right);
	}
	
	//���ҹؼ��֣����Ӷ�ΪO(h)
	Node & _search(Node * node, NodeData_t keyword) const{
		if(node == NULL || keyword == node->data){
			return *node;
		}
		if( keyword < node->data){
			return _search(node->left, keyword);
		}else{
			return _search(node->right, keyword);
		}
	}

};

int main(){
	BiNode a(10), b(9), c(6), d(13);
	
	a.left = &b;
	b.parent = &a;
	
	a.right = &d;
	d.parent = &a;
	
	b.left = &c;
	c.parent = &b;
	
	BiSearchTree<BiNode> tree(&a);
	tree.inorderTreeWalk();
	cout<<endl;

	BiNode *f =  new BiNode(18);
	tree.search(13).right = f;
	f->parent = &tree.search(13);
	cout<<tree.search(18)<<endl;
	cout<<tree.search_i(18)<<endl;
	
	cout<<"minimum "<< tree.minimum()<<endl;
	cout<<"minimum "<< tree.minimum_r()<<endl;
	cout<<"maximum "<< tree.maximum()<<endl;
	cout<<"maximum "<< tree.maximum_r()<<endl;
	
	cout<< tree.search(10) << tree.search(6)<<endl;
	cout<<"successor of 10 " << tree.successor( &tree.search(10)) <<endl;
	cout<<"successor of 6 " << tree.successor( &tree.search(6)) <<endl;
}
