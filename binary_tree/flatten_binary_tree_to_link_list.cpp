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
    void flatten(TreeNode* root) 
    {
        
        stack<TreeNode*> st; 
        TreeNode* p = root;
  
    // Iterate till the stack is not empty 
    // and till root is Null 
    while (p != NULL || !st.empty()) 
    { 
  
        // Check for NULL and insert only p->right->val 
        if (p->right != NULL) 
        { 
            cout<<"p->right->val:"<<p->right->val<<endl;
            st.push(p->right); 
        } 
  
        // Make the Right Left and 
        // left NULL
       //cout<<"p->left->val:"<<p->left->val<<endl;
       //if(p->left != NULL) //this makes a difference:- Time Limit Exceeded
        p->right = p->left; 
        p->left = NULL; 
       
        // Check for NULL 
        if (p->right == NULL && !st.empty()) 
        { 
            cout<<"st.top()->val:"<<st.top()->val<<endl;
            p->right = st.top(); 
            st.pop(); 
        } 
  
        // Iterate 
        p = p->right; 
    } 
        
        
    }
    
};
