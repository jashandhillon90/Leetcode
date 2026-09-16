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
    void getleaf(TreeNode* root,vector<int>& v){
        if(root==NULL)return;
        if(root->left==NULL&&root->right==NULL){
            v.push_back(root->val);

        }
        getleaf(root->left,v);
        getleaf(root->right,v);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;
        getleaf(root1,v1);
        getleaf(root2,v2);
        return v1==v2;

    }
};