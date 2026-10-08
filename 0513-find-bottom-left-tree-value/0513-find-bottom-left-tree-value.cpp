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
int ans;
    int maxDepth=-1;
    void dfs(TreeNode* root,int depth){
        if(root==NULL)return;
        if(depth>maxDepth){
            maxDepth=depth;//pahle depth 0 h toh root then level 1 yani depth 1 ka left then so on
            ans=root->val;
        }
        dfs(root->left,depth+1);//pahle left side jayege
        dfs(root->right,depth+1);//jaha left nhi h vaha right pr jayege
    }
    int findBottomLeftValue(TreeNode* root) {
     dfs(root,0);
     return ans;   
    }
};