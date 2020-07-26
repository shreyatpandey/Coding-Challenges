/*Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.*/
/* Approach - 1*/
class Solution {
    private:
        bool equals(TreeNode* s,TreeNode* t)
        {
            if(s== NULL && t==NULL)
                return true;
            if(s==NULL || t == NULL)
                return false;
            return (s->val == t->val && equals(s->left,t->left) && equals(s->right,t->right)); 
        }
        bool traverse(TreeNode* s,TreeNode* t)
        {
            return (s!=NULL && (equals(s,t) || traverse(s->left,t) || traverse(s->right,t)));
        }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
         return traverse(s,t);
    }

};
/* Approach - 2*/
class Solution {
    private:
        bool isIdentical ( TreeNode* s, TreeNode* t);
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if ( s == NULL && t == NULL)
            return true;
        if ( t == NULL )
            return true;
        if ( s == NULL || t == NULL)
            return false;
        return ( isIdentical(s,t) or isSubtree(s->left,t)or isSubtree(s->right,t)) ;
        
    }
};
bool Solution :: isIdentical ( TreeNode* s, TreeNode* t)
{
    if ( s == NULL && t == NULL)
        return true;
    if( s == NULL || t == NULL)
        return false;
    return ( s->val == t->val && isIdentical(s->left,t->left) && isIdentical(s->right,t->right)) ;
    
}
