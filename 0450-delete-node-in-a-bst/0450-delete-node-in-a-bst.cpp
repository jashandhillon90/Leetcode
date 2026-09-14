class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else {
            // Case 1: No left child
            if (root->left == NULL)
                return root->right;

            // Case 2: No right child
            if (root->right == NULL)
                return root->left;

            // Case 3: Both children exist
            TreeNode* temp = root->right;

            while (temp->left != NULL)
                temp = temp->left;

            root->val = temp->val;

            root->right = deleteNode(root->right, temp->val);
        }

        return root;
    }
};