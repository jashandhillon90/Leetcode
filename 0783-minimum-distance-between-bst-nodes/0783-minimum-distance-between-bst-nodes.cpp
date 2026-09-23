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
public://inorder traversal use krege bcoz min dist to saath wale nodes me hi hogi
    TreeNode* prev=NULL;
    int minDiffInBST(TreeNode* root) {
        if(root==NULL) return INT_MAX;
        int ans=INT_MAX;
        if(root->left!=NULL){//for left subtree
            int leftans=minDiffInBST(root->left);
            ans=min(ans,leftans);
        }
        if(prev!=NULL){//for root
            ans=min(ans,root->val-prev->val);
        }
        //for right subtree
        prev=root;
       if(root->right!=NULL){
            int rightans=minDiffInBST(root->right);
            ans=min(ans,rightans);
        }
        return ans;
    }
};