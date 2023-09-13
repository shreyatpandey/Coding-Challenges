//TC:- O(H)
// SC:- O(1)
//Fastest
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int val = 0;
        int Close = root->val;
        while ( root != NULL )
        {
            val = root->val;
            Close = abs(val-target) < abs(Close - target) ? val:Close;
            root = target < root->val ? root->left : root->right ;
        }
        return Close;
    }
};
