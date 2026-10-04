/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
   stack<TreeNode*>s;
   void StoreLeftNodes(TreeNode* root){
    while(root!=NULL){
        s.push(root);
        root=root->left;
    }
   }
    BSTIterator(TreeNode* root) {
      StoreLeftNodes(root);  
    }
    
    int next() {
        TreeNode* ans=s.top();//curr wala hi toh hoga jo stack k top pr hoga
        s.pop();
        StoreLeftNodes(ans->right);//right node ki saari left values push krege stack me  bcoz right node toh un value se traverse ho jayege
        return ans->val;  
    }
    
    bool hasNext() {
     return s.size()>0;   
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */