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
	
	BiSearchTree & insert(Node * node){
		Node *y = NULL; //y�Ǵ�����ڵ�ĸ��ڵ�
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
		if( y == NULL){ //��Ϊ��
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
	
	//TODO:�ڵ��ɾ��
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
	
	//���������캯������Ϊ˽�У���ֹ�������Զ������Ҳ�С�ı�����
	BiSearchTree(const BiSearchTree & tree){
		root = tree.root;
	}
	
	//����ֵ����������Ϊ˽��
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
	//Ҫ����Ľڵ����
	int N;
	cin>>N;
	
	//�ڵ�
	vector<BiNode *> nodes;
	
	//��
	BiSearchTree<BiNode> tree;
	
	//����
	NodeData_t value;
	BiNode * p_node;
	for( int i =0; i<N; i++){
		cin>>value;
		p_node = new BiNode(value);
		nodes.push_back(p_node);
		tree.insert(p_node);
	}
	
	//����
	tree.inorderTreeWalk();
	cout<<endl;
	
	//����
	for(vector<BiNode *>::iterator it = nodes.begin(); it != nodes.end(); it++){
		assert( *it == &tree.search((*it)->data) );
		assert( *it == &tree.search_i((*it)->data) );
	}
	//�����С
	cout<<"minimum "<< tree.minimum()<<endl;
	cout<<"minimum "<< tree.minimum_r()<<endl;
	cout<<"maximum "<< tree.maximum()<<endl;
	cout<<"maximum "<< tree.maximum_r()<<endl;
	
	//���
	BiNode * begin = *nodes.begin();
	cout<<"successor of first " << tree.successor( &tree.search( begin->data)) <<endl;
	
	//ɾ��
	for(int i =0; i < nodes.size(); i++){
		cout<<"delete " << nodes[i]->data <<endl;
		tree.deleteNode( nodes[i] );
		cout<<"after delete that node: "<<endl;
		tree.inorderTreeWalk();
		cout<<endl;
	}
	
	//��ֹ�����ÿ������캯����˽��
	//BiSearchTree<BiNode> tree2 = tree;
	
	//��ֹ�����ø�ֵ��������˽��
	// BiSearchTree<BiNode> tree2;
	// tree2 = tree;
}
