/* Recursive*/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if ( root == NULL )
            return new TreeNode(val) ;
        else if ( val < root->val)
            root->left = insertIntoBST(root->left,val);
        else
            root->right = insertIntoBST(root->right,val);
        return root;
    }
};


/* Iterative*/
class Solution 
{
    private:
        TreeNode* new_node = NULL;
        TreeNode* parent_return_node = NULL;
        TreeNode* helper = NULL;
    
public:
    TreeNode* insertIntoBST(TreeNode* root, int val)
    {
        new_node = new TreeNode(val);
        if (root == NULL) 
            return new_node;
        parent_return_node = root;
        while (root) 
        {
            helper = root;
            if (val < root->val)
                root = root->left;
            else
                root = root->right;
        }
        if (val < helper->val) 
            helper->left = new_node;
        else 
            helper->right = new_node;
        return parent_return_node;
    }

};
