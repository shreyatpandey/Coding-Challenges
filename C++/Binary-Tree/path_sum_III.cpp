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
public:
    int answer;
    int pathSum(TreeNode* root, int sum) {
		if(!root){
			return 0;
		}

		getSumPaths(root,sum);
		pathSum(root->left,sum);
		pathSum(root->right,sum);

        return answer;
    }

private:
	void getSumPaths(TreeNode *root, int sum){
		
		if(!root){
			return;
		}

		if(root->val == sum){
			answer++;
		}

		sum -= root->val;

		getSumPaths(root->left,sum);
		getSumPaths(root->right,sum);
	}


    
};
