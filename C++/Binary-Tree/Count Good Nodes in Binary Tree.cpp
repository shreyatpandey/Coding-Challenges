//Approach :- DFS
//SC:- O(n)

/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.
Input:
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
*/
class Solution {
    private:
        int iGoodNodes = 0;
        void DFSTraversal(TreeNode* root,int&GoodNodes,int PreviousMax);
public:
    int goodNodes(TreeNode* root) {
        if ( root == NULL )
            return iGoodNodes;
        DFSTraversal(root,iGoodNodes,INT_MIN);
        return iGoodNodes;
        
    }
};
void Solution::DFSTraversal(TreeNode* root,int&GoodNodes,int PreviousMax)
{
    if ( root == NULL)
        return ;
    if ( root->val >= PreviousMax )
    {
        PreviousMax = max(PreviousMax,root->val);
        GoodNodes += 1;
    }
    DFSTraversal(root->left,GoodNodes,PreviousMax);
    DFSTraversal(root->right,GoodNodes,PreviousMax);
}
