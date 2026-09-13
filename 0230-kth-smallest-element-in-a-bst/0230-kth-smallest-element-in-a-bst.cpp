class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != NULL || !st.empty()) {
            // Go to the leftmost node
            while (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }

            // Process node
            curr = st.top();
            st.pop();

            k--;

            if (k == 0)
                return curr->val;

            // Move to right subtree
            curr = curr->right;
        }

        return -1;
    }
};