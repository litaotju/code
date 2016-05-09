#include <iostream>
#include <stack>
#include <cassert>
#include <vector>
using namespace std;

typedef int NodeData_t;

template<class Node> 
class BiSearchTree {
public:
	Node * root;
	
	BiSearchTree(Node * ro = NULL): root(ro){ 
		cout<<"Cunstruction"<<endl;
	}
	
	//中序遍历
	void inorderTreeWalk(){
		_inorderTreeWalk(root);
	}
	
	//TODO:非递归版本的中序遍历
	void inorderTreeWalk_i(Node * x){ 
		stack<Node *> node_stack;
	}
	
	//递归版本的搜索
	Node & search( NodeData_t keyword){
		return _search(root, keyword);
	}
	
	//迭代版本的搜索
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
	
	//TODO:二叉查找树的后继结点理解
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
	
	BiSearchTree & insert(Node * node){
		Node *y = NULL; //y是待插入节点的父节点
		Node *x = root;
		while( x != NULL){
			y = x;
			if( node->data < x->data){
				x = x->left;
			}else{
				x = x->right;
			}
		}
		node->parent = y;
		if( y == NULL){ //树为空
			root = node;
			return *this;
		}
		if( node->data > y->data){
			y->right = node;
		}else{
			y->left = node;
		}
		return *this;
	}
	
	//TODO:节点的删除
	BiSearchTree & deleteNode(Node *node){
		if(node == NULL)
			return *this;
		Node * y, *x;
		if( node->left == NULL || node->right==NULL)
		{
			y = node;
		}
		else{
			y = &successor(node);
		}
		if(y->left != NULL){
			x = y->left;
		}else{
			x = y->right;
		}
		if(x != NULL){
			x->parent = y->parent;
		}
		if( y->parent ==NULL){
			root = x;
		}else if( y == y->parent->left){
			y->parent->left = x;
		}
		return *this;
	}
private:
	//中序遍历，复杂度为O(n)
	void _inorderTreeWalk(Node * x){
		if( x == NULL) return;
		_inorderTreeWalk(x->left);
		cout<< *x <<", ";
		_inorderTreeWalk(x->right);
	}
	//查找关键字，复杂度为O(h)
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
	
	//将拷贝构造函数声明为私有，防止编译器自动生成且不小心被调用
	BiSearchTree(const BiSearchTree & tree){
		root = tree.root;
	}
	
	//将赋值操作符声明为私有
	BiSearchTree & operator =(const BiSearchTree &tree){
		return *this;
	}
};


class BiNode{
public:
	NodeData_t data;
private:
	BiNode * left;
	BiNode * right;
	BiNode * parent;
	friend BiSearchTree<BiNode>;
public:
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


int main(){	
	//要输入的节点个数
	int N;
	cin>>N;
	
	//节点
	vector<BiNode *> nodes;
	
	//树
	BiSearchTree<BiNode> tree;
	
	//输入
	NodeData_t value;
	BiNode * p_node;
	for( int i =0; i<N; i++){
		cin>>value;
		p_node = new BiNode(value);
		nodes.push_back(p_node);
		tree.insert(p_node);
	}
	
	//遍历
	tree.inorderTreeWalk();
	cout<<endl;
	
	//搜索
	for(vector<BiNode *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		assert( *it == &tree.search((*it)->data) );
		assert( *it == &tree.search_i((*it)->data) );
	}
	//最大最小
	cout<<"minimum "<< tree.minimum()<<endl;
	cout<<"minimum "<< tree.minimum_r()<<endl;
	cout<<"maximum "<< tree.maximum()<<endl;
	cout<<"maximum "<< tree.maximum_r()<<endl;
	
	//后继
	BiNode * begin = *nodes.begin();
	cout<<"successor of first " << tree.successor( &tree.search( begin->data)) <<endl;
	
	//删除
	for(int i =0; i < nodes.size(); i++){
		cout<<"delete " << nodes[i]->data <<endl;
		tree.deleteNode( nodes[i] );
		cout<<"after delete that node: "<<endl;
		tree.inorderTreeWalk();
		cout<<endl;
	}
	
	//禁止：调用拷贝构造函数：私有
	//BiSearchTree<BiNode> tree2 = tree;
	
	//禁止：调用赋值操作符：私有
	// BiSearchTree<BiNode> tree2;
	// tree2 = tree;
}
