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
   vector<int> arr;//pahle inorder me sort krlenge then mid find krke tree build krege
   void inorder(TreeNode* root){
    if(root==NULL)return;
    inorder(root->left);
    arr.push_back(root->val);
    inorder(root->right);
   }
   TreeNode* build(int left,int right){
    if(left>right)return NULL;
    int mid=left+(right-left)/2;
    TreeNode* root=new TreeNode(arr[mid]);
    root->left=build(left,mid-1);
    root->right=build(mid+1,right);
    return root;
   }
    TreeNode* balanceBST(TreeNode* root) {
     inorder(root);
     return build(0,arr.size()-1);   
    }
};