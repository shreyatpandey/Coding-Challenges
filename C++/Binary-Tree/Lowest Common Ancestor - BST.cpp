/*Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: 
“The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]*/
/* BST properties:-
  1. Left subtree of a node N contains nodes whose values are lesser than or equal to node N's value.
  2. Right subtree of a node N contains nodes whose values are greater than node N's value.
  3. Both left and right subtrees are also BSTs. */
/*Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

  
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( root == NULL )
        {
            return NULL;
        }
        if ( root == p || root == q)    
        {
            return root;
        }
        root->left = lowestCommonAncestor( root->left, p, q);
        root->right = lowestCommonAncestor(root->right,p,q);
        if ( root->left != NULL && root->right != NULL)
        {
            return root;
        }
        else
        {
            return ( root->left ? root->left : root->right);
        }        
    }
};
