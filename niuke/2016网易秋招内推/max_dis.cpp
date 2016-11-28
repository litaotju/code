/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/


//最大和最小叶子节点的距离

class Tree {
public:
    int getDis(TreeNode* root) {
        // write code here
        mMax = root;
        mMin = root;
        in_order(root);
        return leastCommanAncestor(root, mMax, mMin);
    }
private:
	typedef TreeNode treenode;
    int  leastCommanAncestor(treenode *root, treenode *a, treenode *b){
        vector<treenode *> apath;
        vector<treenode *> bpath;
        apath.push_back(root);
        bpath.push_back(root);
        findNode(root, apath, a);
        findNode(root, bpath, b);
        auto itera = apath.begin();
        auto iterb = bpath.begin();
        while( *itera == *iterb ){
            itera++;
            iterb++;
        }
        return apath.end()-itera + bpath.end()-iterb;
    }
    
    bool findNode(treenode *root, vector<treenode *> & path,  treenode *a){
        if(root==NULL)
            return false; 
        if(root == a){
            return true;
        }
        if(root->left){
            path.push_back(root->left);
            if(findNode(root->left, path, a))
                return true;
            else
                path.pop_back();
        }
        if(root->right){
            path.push_back(root->right);
            if(findNode(root->right, path, a))
                return true;
            else
                path.pop_back();
        }
        return false;
    }
    
    void in_order(TreeNode* root){
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL){
            if( root->val > mMax->val)
                mMax = root;
            if( root->val < mMin->val)
                mMin = root;
        }
        in_order(root->left);
        in_order(root->right);
    }
    treenode *mMax;
    treenode *mMin;
};