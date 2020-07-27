/*
or example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2
 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

*/



class Solution {
    private:
        void Inorder(TreeNode* root, vector<int>&InorderStore);
public:
    vector<int> findMode(TreeNode* root) {
        vector<int>InorderStore;
        vector<int>Result;
        Inorder(root,InorderStore);
        map<int,int>FrequencyCount;
        using pair_type = decltype(FrequencyCount)::value_type;
        for(auto &x:InorderStore)
        {
            if ( FrequencyCount.count(x) > 0)
            {
                FrequencyCount[x]++;
            }
            else
            {
                FrequencyCount[x] = 1;
            }
        }
        auto MaxCount = max_element(begin(FrequencyCount),end(FrequencyCount),[](const pair_type & p1, const pair_type & p2) {
        return p1.second < p2.second;
    } ) ;
        for(auto &x:FrequencyCount)
        {
            if ( x.second == MaxCount->second)
            {
                Result.emplace_back(x.first);
            }
        }
        return Result;
        
        
    }
};
void Solution::Inorder(TreeNode* root, vector<int>&InorderStore)
{
    if ( root == NULL)
        return ;
    Inorder(root->left,InorderStore);
    InorderStore.emplace_back(root->val);
    Inorder(root->right,InorderStore);
}
