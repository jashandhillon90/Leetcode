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
   bool check(TreeNode* root,TreeNode* low,TreeNode* high){
    if(root==NULL) return true;
    if(low!=NULL&&low->val>=root->val) return false;
    if(high!=NULL&&high->val<=root->val) return false;
    return (check(root->left,low,root)&&
             check(root->right,root,high)
    );
   }
    bool isValidBST(TreeNode* root) {
  return check(root,NULL,NULL);
      
    }
// TreeNode* prev = NULL;
//     bool isValidBST(TreeNode* root) {
//         if (root == NULL)
//             return true;
//         if (!isValidBST(root->left))
//             return false;
//         if (prev != NULL && root->val <= prev->val)
//             return false;
//         prev = root;
//         return isValidBST(root->right);
//     }
};
