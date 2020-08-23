class Solution {
   private:
        void preorderTraversal_output(TreeNode* root, vector<int>&preorderTraversal_ret)
        {
            if(root == NULL)
                return;
            preorderTraversal_ret.push_back(root->val);
            preorderTraversal_output(root->left,preorderTraversal_ret);
            preorderTraversal_output(root->right,preorderTraversal_ret);
        }
public:
    vector<int> preorderTraversal_recursion(TreeNode* root) {
         vector<int>preorderTraversal_ret;
        if(root == NULL)
            return preorderTraversal_ret;
        
        preorderTraversal_output(root,preorderTraversal_ret);
        return preorderTraversal_ret;
        
    }
   vector<int> preorderTraversal_stack(TreeNode* root)
   {
       vector<int>preorderTraversal_value;
        if(root == NULL)
            return preorderTraversal_value;
        stack<TreeNode*>preorderTraversal_stack;
        preorderTraversal_stack.emplace(root);
        while(!preorderTraversal_stack.empty())
        {
            TreeNode* preorderTraversal_node = preorderTraversal_stack.top();
            preorderTraversal_value.emplace_back(preorderTraversal_node->val);
            preorderTraversal_stack.pop();
            
            if(preorderTraversal_node->right)
                preorderTraversal_stack.emplace(preorderTraversal_node->right);
            if(preorderTraversal_node->left)
                preorderTraversal_stack.emplace(preorderTraversal_node->left);
            
        }
        return preorderTraversal_value;  
   }
    
      
};
