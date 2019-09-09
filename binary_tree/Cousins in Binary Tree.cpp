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
    private:
        queue<TreeNode*>store_node;
        int size_each_level = 0;
        bool found_x = true;
        bool found_y = true;
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)
            return false;
        store_node.emplace(root);
        while(store_node.size()>0)
        {
            size_each_level = store_node.size();
            found_x = false;
            found_y = false;
            TreeNode* x_node = NULL;
            TreeNode* y_node = NULL;
            while(size_each_level>0)
            {
                TreeNode* parent_node_each_level = store_node.front();
                store_node.pop();
                if(parent_node_each_level->right)
                {
                    store_node.emplace(parent_node_each_level->right);
                     if(parent_node_each_level->right->val==x )
                    {
                        found_x=true;
                        x_node = parent_node_each_level;
                    }
                    else if(parent_node_each_level->right->val==y)
                    {
                        found_y=true;
                        y_node = parent_node_each_level;
                    }
                }
                 if(parent_node_each_level->left)
                {
                    store_node.emplace(parent_node_each_level->left);
                     if(parent_node_each_level->left->val==x )
                    {
                        found_x=true;
                        x_node=parent_node_each_level;
                    }
                    else if(parent_node_each_level->left->val==y)
                    {
                        found_y=true;
                        y_node = parent_node_each_level;
                    }
                }
                if(found_x==true && found_y==true && x_node!=y_node)
                    return true;
                size_each_level -= 1;
            }   
                
                
            }
        return false;
            
        }
        
};
