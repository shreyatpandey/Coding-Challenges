/*
Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root.
Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.  (The values of the nodes may still be duplicates)
Example 1

Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
*/

**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 //Leetcode - Solution Approach
 //Issue was regarding Anti-clockwise
class Solution {
    private :
        bool isLeaf ( TreeNode* root ) ;
        void AddLeaves ( vector<int>& Result, TreeNode* root);
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int>Result ;
        if ( root == NULL)
        {
            return Result;
        }
        if ( isLeaf ( root ) == false)
        {
            Result.emplace_back(root->val);
        }
        TreeNode* LeftTree = root->left ;
        while ( LeftTree != NULL)
        {
            if ( isLeaf ( LeftTree ) == false)
            {
                Result.emplace_back(LeftTree->val);
            }
            if ( LeftTree->left != NULL )
            {
                LeftTree = LeftTree->left;
            }
            else
            {
                LeftTree = LeftTree->right;
            }
        }
        AddLeaves ( Result, root) ;
        stack<int>HoldValues ;
        LeftTree = root->right ;
        while ( LeftTree != NULL)
        {
            if ( isLeaf ( LeftTree )  == false)
            {
                HoldValues.emplace(LeftTree->val);
            }
            if ( LeftTree->right != NULL)
            {
                LeftTree = LeftTree->right;
            }
            else
            {
                LeftTree = LeftTree->left;
            }
        }
        while ( HoldValues.size() > 0)
        {
            Result.emplace_back(HoldValues.top());
            HoldValues.pop();
        }
        return Result;
        
    }
};
bool Solution::isLeaf ( TreeNode* root)
{
    return ( root->left == NULL && root->right == NULL);
        
}
void Solution::AddLeaves( vector<int>&Result, TreeNode* root)
{
    if  ( isLeaf (root))
    {
        Result.emplace_back(root->val);
    }
    else
    {
        if ( root->left != NULL)
        {
            AddLeaves ( Result, root->left );
        }
        if ( root->right != NULL )
        {
            AddLeaves ( Result, root->right );
        }
    }
}

