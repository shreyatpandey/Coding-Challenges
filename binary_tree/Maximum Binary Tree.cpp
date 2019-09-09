/*
Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

The root is the maximum number in the array.
The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
Construct the maximum tree by the given array and output the root node of this tree.
Example 1:
Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1
 */
class Solution 
{
    private:
        stack<TreeNode*>stack_input;
        TreeNode *left_node = NULL;

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)   
        {
            TreeNode *node = new TreeNode(nums[i]);
            left_node = NULL;
            while (stack_input.size() && stack_input.top()->val < nums[i])  
            {
                left_node = stack_input.top();
                stack_input.pop();
            }
            node->left = left_node;
            if (stack_input.size()) 
            {
                stack_input.top()->right = node;
            }
            stack_input.push(node);
        }
        while (stack_input.size() > 1) 
            stack_input.pop();
        return stack_input.top();
    }
};
