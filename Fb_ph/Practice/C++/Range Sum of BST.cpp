/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int ans = 0;
        stack<TreeNode*> st;
        st.emplace(root);
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (node != NULL) {
                if (L <= node->val && node->val <= R)
                    ans += node->val;
                if (L < node->val)
                    st.emplace(node->left);
                if (node->val < R)
                    st.emplace(node->right);
            }
        
    }
        return ans;
    }
};
