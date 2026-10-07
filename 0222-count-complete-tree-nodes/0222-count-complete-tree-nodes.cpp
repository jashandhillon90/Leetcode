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
    int countNodes(TreeNode* root) {
     if(root==NULL)return 0;
     int leftHeight = 0;
        int rightHeight = 0;

        TreeNode* left = root;
        TreeNode* right = root;

        // Find left height
        while (left) {
            leftHeight++;
            left = left->left;
        }

        // Find right height
        while (right) {
            rightHeight++;
            right = right->right;
        }

        // Perfect binary tree
        if (leftHeight == rightHeight) {
            return (1 << leftHeight) - 1;
        }

       //not perfect
     return 1+countNodes(root->left)+countNodes(root->right);      
    }
};