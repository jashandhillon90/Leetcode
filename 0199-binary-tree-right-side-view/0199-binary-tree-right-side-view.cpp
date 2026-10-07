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
    vector<int> ans;
    void solve(TreeNode* root,int level){
        if(root==NULL) return;
        if(level==ans.size()){//pahle level 0 hoga or ans ka size bhi 0 h then ans me value push hokr size increase hoga or level bhi increase hoga 
            ans.push_back(root->val);
        }
        solve(root->right,level+1);
        solve(root->left,level+1);//jaha sirf left nodes h next level se
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};