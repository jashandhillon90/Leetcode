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
    unordered_map<int,int>mp;
    int maxfreq=0;
int dfs(TreeNode* root){
    if(root==NULL)return 0;
    int left=dfs(root->left);
    int right=dfs(root->right);
    int sum=root->val+left+right;
    mp[sum]++;
    maxfreq=max(maxfreq,mp[sum]);
    return sum;
}
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for(auto it:mp){
            if(it.second==maxfreq){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};