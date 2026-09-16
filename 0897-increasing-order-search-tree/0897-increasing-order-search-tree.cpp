class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* ans = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL)
            return;

        inorder(root->left);

        if (ans == NULL)
            ans = root;
        else
            prev->right = root;

        root->left = NULL;
        prev = root;

        inorder(root->right);
    }

    TreeNode* increasingBST(TreeNode* root) {
        inorder(root);
        return ans;
    }
};