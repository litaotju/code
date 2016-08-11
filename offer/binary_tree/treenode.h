template <class T>
struct TreeNode{
    T val;
    TreeNode<T> * left;
    TreeNode<T> * right;
};

template <class T>
TreeNode<T> * build_tree(){
    TreeNode<T> *nodes = new TreeNode<T> [10];
    for(int i=0; i<10; i++){
        nodes[i].val = i+1;
        if(2*i+1 < 10)
            nodes[i].left = &nodes[2*i+1];
        else
            nodes[i].left = nullptr;
        if( 2*i+2 < 10)
            nodes[i].right= &nodes[2*i+2];
        else
            nodes[i].right = nullptr;
    }
    return nodes;
}