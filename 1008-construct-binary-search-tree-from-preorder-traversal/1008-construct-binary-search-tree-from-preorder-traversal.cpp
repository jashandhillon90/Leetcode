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
class Solution {
public:
    TreeNode* helper(vector<int>& preorder, int &i,int bound){
     if(i>=preorder.size()||preorder[i]>bound) return NULL;
     TreeNode* root=new TreeNode(preorder[i++]);// preorder me first hi root hoti h
     root->left=helper(preorder,i,root->val);// kyuki left ka bound wahi root hogi upper bound we are using in it
     root->right=helper(preorder,i,bound);// kyuki right lk liye bound previous root wala bound hoga
     return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,i,INT_MAX);
    }
};