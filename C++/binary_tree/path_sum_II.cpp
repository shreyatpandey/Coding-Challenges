class Solution {
    vector<vector<int>>result;
    vector<int>path;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
{
         
        if(root == NULL) 
        {
            return result;
        }
        path.emplace_back(root->val);
       
        sum -= root->val;
  
        if(sum == 0 && !root->left && !root->right) 
        {
            result.emplace_back(path);
            return result;
        }
            
        pathSum(root->left, sum);
        if(root->left)
        {
            path.pop_back();
        }
        pathSum(root->right, sum);
        if(root->right)
        {
            path.pop_back();
        }
        return result;
    }
        
};
