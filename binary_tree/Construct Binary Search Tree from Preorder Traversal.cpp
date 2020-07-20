//Approach-1: Recursion
//TC:- O(N)
//SC:- O(N)
class Solution {
    private:
        TreeNode* BuildBST(vector<int>&preorder,int lower, int upper);
        int Index = 0;
        int SizeOfPreorder = 0;
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       SizeOfPreorder = preorder.size();
        return BuildBST(preorder,INT_MIN,INT_MAX);
        
    }
};
TreeNode* Solution::BuildBST(vector<int>&preorder,int lower,int upper)
{
    if ( Index == SizeOfPreorder)
        return NULL;
    int value = preorder[Index] ;
     if (value < lower || value > upper) 
         return nullptr;

    Index ++;
    TreeNode* root = new TreeNode(value);
    root->left = BuildBST(preorder,lower, value);
    root->right = BuildBST(preorder,value, upper);
    return root;
}


//Approach:- 2 Using Stack
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
