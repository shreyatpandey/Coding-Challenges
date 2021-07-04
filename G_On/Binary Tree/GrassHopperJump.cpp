/*
There is a grasshopper that starts from the root node, if the hopper hops to a node with no children the hopper is stuck and can't move further. 
If the grasshopper has the option to move then it has to make the hop. Basically the goal is to find the probability of the grasshopper landing at each node.

Example
p : probability
parent -> [children]

           (p : 0) -> [(p: 0) -> [(p:1/3)] , (p: 0) -> [(p:1/6), (p:1/6)] , (p: 1/3)]
*/
/* Clarifying questions:- Is the denominator like 3,6 equivalent to the depth of the node */
struct TreeNode{
    
    int val;
    double p;//for non-leaf: probability to move to left children, so with 1-p probability move to right children
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int v,double pr){
        val=v;
        p=pr;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    
public:
    
    vector<TreeNode*> grasshopper(TreeNode* root){

        vector<TreeNode*>ans;        
        fun(root,ans,1.0);
        return ans;
    }
    
    void fun(TreeNode* root,vector<TreeNode*>& ans,double probab){
     
        if(root==NULL)return;
        
        double p=root->p;
        root->p=probab;
        if(root->left==NULL&&root->right==NULL)ans.push_back(root);
        
        fun(root->left,ans,p*probab);
        fun(root->right,ans,(1.0-p)*probab);
        
    }
};
