class Solution {
public:
   
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>preorderTraversal_ret;
        if(root == NULL)
            return preorderTraversal_ret;
        
        preorderTraversal_output(root,preorderTraversal_ret);
        return preorderTraversal_ret;
        
    }
    private:
        void preorderTraversal_output(TreeNode* root, vector<int>&preorderTraversal_ret)
        {
            if(root == NULL)
                return;
            preorderTraversal_ret.push_back(root->val);
            preorderTraversal_output(root->left,preorderTraversal_ret);
            preorderTraversal_output(root->right,preorderTraversal_ret);
        }   
};
