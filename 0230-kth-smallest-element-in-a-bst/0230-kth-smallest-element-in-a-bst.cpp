class Solution {
public:
// sort order bcoz inorder 
int prevorder=0;
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return -1;
        if(root->left){
            int leftans=kthSmallest(root->left,k);
            if(leftans!=-1) return leftans;
        }
        if(prevorder+1==k){
            return root->val;
        }
        prevorder=prevorder+1;
        if(root->right){
            int rightans=kthSmallest(root->right,k);
            if(rightans!=-1) return rightans;
        }

        return -1;
    }
};