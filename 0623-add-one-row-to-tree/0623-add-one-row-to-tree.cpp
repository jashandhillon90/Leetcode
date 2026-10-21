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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
     if(root==NULL)return NULL;
     if(depth==1){//ROOT ME INSERT KRNI H VALUE TOH
        TreeNode* NewRoot=new TreeNode(val);
        NewRoot->left=root;
        return NewRoot;
     }   
     if(depth==2){
        TreeNode* leftNode=new TreeNode(val);
        TreeNode* rightNode=new TreeNode(val);
        //ab jo root k left h vo leftnode k left ho jayenge
        leftNode->left=root->left;
        rightNode->right=root->right;
        root->left=leftNode;
        root->right=rightNode;
        return root;
     }
     root->left=addOneRow(root->left,val,depth-1);//hr baar neeche move krege ek then jb tak required level tk na pahunch jaye
     root->right=addOneRow(root->right,val,depth-1);
     return root;
    }
};