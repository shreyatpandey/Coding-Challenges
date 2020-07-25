/*
Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4
*/

/* Approach -1 //Recursive + Iterative
TC:- O(N) - linear seach for comparasion
SC:- O(N) 
Total Running Time:- 95.17% faster
*/
class Solution {
    private:
        void InorderTraversal(vector<int>&InorderVector,TreeNode* root);
        int Target;
public:
    int closestValue(TreeNode* root, double target) {
        vector<int>InorderVector;
        InorderTraversal(InorderVector,root);
        return *min_element(InorderVector.begin(),InorderVector.end(),[target](int a,int b){ return abs(a - target)<abs(b-target) ;}); 
    }
};
void Solution :: InorderTraversal ( vector<int>&InorderVector,TreeNode* root)
{
    if ( root == NULL )
        return ;
    InorderTraversal(InorderVector,root->left);
    InorderVector.emplace_back(root->val);
    InorderTraversal(InorderVector,root->right);
    
}

/* Approach - 2 // Recursive
TC:- O(N) or O(h)
SC:- O(1)
Total Running Time:- 48.17% faster
*/
class Solution {
    private:
        int Result = INT_MAX;
public:
    int closestValue(TreeNode* root, double target) {
        if ( root == NULL )
            return Result;
        double current = (double)root->val;
        if ( current == target)
            return root->val;
      if( Result ==INT_MAX || abs(Result-target)> abs(current-target))
            Result = current; 
        return ( current>target ? closestValue(root->left,target) : closestValue(root->right,target));
    }
    
};

