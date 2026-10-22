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
    int count=0;
    int maxcount=0;
    bool first=true;
    int prevVal=0;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        //hr node ka count bnayenge
        if(!first&&root->val==prevVal){
            count++;
        }else{
            count=1;
        }
        if(count>maxcount){
            maxcount=count;
            ans.clear();
            ans.push_back(root->val);
        }else if(count==maxcount){
            ans.push_back(root->val);
        }
        prevVal=root->val;
        first=false;//kyuki count wali condition check krni hogi
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
     inorder(root);//sorted order me traverse krke pichli value k saath compare krege
     return ans;   
    }
};