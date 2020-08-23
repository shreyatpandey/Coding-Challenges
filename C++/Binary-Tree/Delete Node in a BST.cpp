/*
root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
*/
class Solution {
    private:
        TreeNode* FindMin(TreeNode* root);
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if ( root == NULL)
            return root;
       else if ( root->val > key)
            root->left = deleteNode(root->left,key);
        else if ( root->val < key)
            root->right = deleteNode(root->right,key);
        else{
            /*Case-1: When the node to be deleted has no child */
            if ( root->right==NULL && root->left == NULL)
            {
                delete ( root ) ;
                root = NULL;
            }
            /*Case-2: When the node to be deleted has one child */
            else if ( root->right == NULL)
            {
                TreeNode* temp = root ;
                root = root->left;
                delete ( temp );
            }
            else if ( root->left == NULL )
            {
                TreeNode* temp = root;
                root = root->right ;
                delete ( temp);
            }
            /* Case-3: When the node to be delete has two child*/
            else
            {
                TreeNode* temp = FindMin(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right,temp->val);
            }
        }
         return root;
        
    }
};
TreeNode* Solution :: FindMin ( TreeNode* root)
{
    while ( root->left != NULL )
    {
        root = root->left ;
    }
    return root;
    
}
    
