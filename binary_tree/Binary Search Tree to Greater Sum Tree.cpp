/*
Given the root of a binary search tree with distinct values, 
modify it so that every node has a new value equal to the sum of the values of the original tree that 
are greater than or equal to node.val.
*/
class Solution {
    private:
        void transformtree(TreeNode* root,int *sum);
public:
    TreeNode* bstToGst(TreeNode* root) {
        if (root == NULL)
            return NULL;
        int sum = 0;
        transformtree(root,&sum);
        return root;
        
    }
};
void Solution::transformtree(TreeNode* root,int *sum) //traversal in reverse inorder
{
    if (root == NULL)
        return;
    transformtree(root->right,sum); 
    *sum = *sum + root->val;
    root->val = *sum;
    transformtree(root->left,sum);
    
}
