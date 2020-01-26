//TC:- O(n)
class Solution {
    private:
        stack<TreeNode*>storenode;
        TreeNode* helper = NULL;
        TreeNode* root = NULL;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 1)
            return (new TreeNode(preorder[0]));
        root = new TreeNode(preorder[0]);
        storenode.emplace(root);
        for(int i=1;i<preorder.size();i++)
        {
            helper = NULL;
            while(storenode.size()>0 && preorder[i] > storenode.top()->val)
            {
                helper = storenode.top();
                storenode.pop();
            }
            if(helper)
            {
                helper->right = new TreeNode(preorder[i]);
                storenode.emplace(helper->right);
            }
            else
            {
                storenode.top()->left = new TreeNode(preorder[i]);
                storenode.emplace(storenode.top()->left);
            }
        }
        return root;
        
    }
};
