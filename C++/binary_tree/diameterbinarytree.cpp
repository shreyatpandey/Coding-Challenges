/*Given a binary tree, you need to compute the length of the diameter of the tree. 
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].*/


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
        int height_of_binary_tree(TreeNode* root)
        {
            if(root == NULL)
                return 0;
          int left_hand_side = height_of_binary_tree(root->left);
          int right_hand_side = height_of_binary_tree(root->right);
           
           return(left_hand_side>right_hand_side?1+left_hand_side:1+right_hand_side);
        }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left_side_tree = height_of_binary_tree(root->left);
        int right_side_tree = height_of_binary_tree(root->right);
        
        int left_side_diameter = diameterOfBinaryTree(root->left);
        int right_side_diameter = diameterOfBinaryTree(root->right);
        
        return (max(left_side_tree + right_side_tree ,max(left_side_diameter,right_side_diameter)));
        
        
        
    }
};

