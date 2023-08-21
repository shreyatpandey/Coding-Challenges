/*Recursive Approach */
class Solution
{
  //int level = 1;
  public:
    int getlevelofnode(TreeNode* node,int data,int level)
    {
     if (root == NULL)
        return 0;
       
       if (root->val == data)
          return level;
       int left_side_level  = getlevelofnode(node->left,data,level+1);
       if(left_side_level)
          return left_side_level;
        left_side_level = getlevelofnode(node->right,data,level+1);
        
        return left_side_level;
     }
 };
 
 /*Iterative Approach */
 class Solution
 {
    public:
      int getlevelofnode(TreeNode* node,int data)
      {
          queue<node*> node_at_each_level; 
          int level = 1; 
          node_at_each_level.push(root); 
          node_at_eah_level.push(NULL); 
          while (node_at_each_level.size() > 0) 
          { 
              TreeNode* temp = node_at_each_level.front(); 
              node_at_each_level.pop(); 
              if (temp == NULL) 
              {
                  if (node_at_each_level.front() != NULL) 
                  { 
                      node_at_each_level.push(NULL); 
                  } 
                  level += 1; 
              } 
              else 
              { 
                  if (temp->data == data) 
                  { 
                      return level; 
                  } 
                  if (temp->left) 
                  { 
                      node_at_each_level.push(temp->left); 
                  } 
                  if (temp->right) 
                  { 
                      node_at_each_level.push(temp->right); 
                  } 
              } 
          } 
    return 0; 
      
      
      }
      
};
