
  
  struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int parent_value = root->val;
        int p_value = p->val;
        int q_value = q->val;
        
        if(p_value > parent_value && q_value > parent_value)
            return lowestCommonAncestor(root->right,p,q);
        else if(p_value<parent_value && q_value<parent_value)
            return lowestCommonAncestor(root->left,p,q);
        else
            return root;
            
        
    }
};
