class Solution {
public:
    long ans = LONG_MAX;
    int mn;

    void dfs(TreeNode* root) {
        if (!root) return;

        if (root->val > mn && root->val < ans)
            ans = root->val;

        dfs(root->left);
        dfs(root->right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        mn = root->val;
        dfs(root);

        return ans == LONG_MAX ? -1 : ans;
    }
};