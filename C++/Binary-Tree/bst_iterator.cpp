/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> bst_stack;
public:
    BSTIterator(TreeNode *root) {
        push_to_left(root);
        
        
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(bst_stack.empty())
            return false;
        else
            return true;
        
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* node = bst_stack.top();
        bst_stack.pop();
        push_to_left(node->right);
        return node->val;
        
        
        
    }
    private:
    void push_to_left(TreeNode *root)
    {
        if(root !=NULL)
        {
            bst_stack.push(root);
            push_to_left(root->left);
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
