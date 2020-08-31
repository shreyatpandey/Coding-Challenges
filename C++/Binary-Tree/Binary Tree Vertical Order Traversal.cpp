/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
 //Approach-1: BFS [ Hash Map + Sorting ]
 //TC: O(N Log N ) , where N is the number of nodes
 //SC: O(N), 
 //faster than 9.71% of C++ Submission
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>Result ;
        if ( root == NULL )
            return Result;
        unordered_map<int,vector<int>>columnTable ;
        queue<pair<TreeNode*,int>>BFSQueue ;
        int column = 0;
        BFSQueue.push({root,column});
        while ( BFSQueue.size() > 0)
        {
            auto LevelOrder  = BFSQueue.front();
            BFSQueue.pop();
            root = LevelOrder.first;
            column = LevelOrder.second;
            if ( root != NULL)
            {
                if ( columnTable.count(column) == 0)
                {
                    columnTable.insert(make_pair(column,vector<int>{}));
                }
            columnTable[column].emplace_back(root->val);
            BFSQueue.push({root->left,column-1});
            BFSQueue.push({root->right,column+1});
            }
        }
        vector<int>SortedKeys ;
        for ( auto &x: columnTable)
        {
            SortedKeys.emplace_back(x.first);
        }
        sort(SortedKeys.begin(),SortedKeys.end());
        for ( auto &x:SortedKeys)
        {
            Result.emplace_back(columnTable[x]);
        }
        return Result;
        
    }
};
