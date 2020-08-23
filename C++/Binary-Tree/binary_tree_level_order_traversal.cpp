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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>level_order_value;
        vector<int>level_order_loop;
        queue<TreeNode*>queue_level_order;
        if(root == NULL)
            return level_order_value;
        queue_level_order.emplace(root);
        while(!queue_level_order.empty())
        {
            int length_each_level = queue_level_order.size();
            while(length_each_level)
            {
                TreeNode* queue_node = queue_level_order.front();
                level_order_loop.emplace_back(queue_node->val);
                queue_level_order.pop();
                if(queue_node->left != NULL)
                    queue_level_order.emplace(queue_node->left);
                if(queue_node->right != NULL)
                    queue_level_order.emplace(queue_node->right);
                length_each_level -= 1;
                    
            }
            if(level_order_loop.size())
                level_order_value.emplace_back(level_order_loop);
            level_order_loop.erase(level_order_loop.begin(),level_order_loop.end());
        }
        return level_order_value;
      
        
        
    }
};
