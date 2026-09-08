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
    int sum = 0;

    void Add(TreeNode* root) {
        if(root == NULL) return;

        sum += root->val;

        Add(root->left);
        Add(root->right);
    }

    bool checkTree(TreeNode* root) {
        sum = 0;

        Add(root->left);
        Add(root->right);

        return sum == root->val;
    }
};