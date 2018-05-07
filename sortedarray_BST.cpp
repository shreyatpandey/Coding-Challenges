#include<bits/stdc++.h>
using namespace std;


struct TreeNode
{
  int data;
  struct TreeNode *left;
  struct TreeNode *right;
  };
  
 struct TreeNode* NewNode(int data)
 {
   struct TreeNode* temp = new TreeNode;
   temp->data = data;
   temp->left = NULL;
   temp->right = NULL;
   return temp;
  }; 
  
 class Solution
 {
   public:
   TreeNode* sortedArrayToBST(vector<int>& nums)
   {
     
     return sortedArrayToBST1(nums,0,nums.size()-1);
    
    }
   private:
   TreeNode *sortedArrayToBST1(vector<int>&nums,int start_value,int end_value)
   {
    
     if(start_value <= end_value)
     {
       /*auto mid= nums.begin() + nums.size()/2 ;*/
        int middle = start_value+(end_value-start_value)/2;
        
        struct TreeNode *head_node = NewNode(nums[middle]);
    
     head_node->right = sortedArrayToBST1(nums,start_value,middle-1);
     head_node->right = sortedArrayToBST1(nums,middle,end_value);
     return head_node;
     }
     return NULL;
    }
    
 };
 
 void print(struct TreeNode* head)
 {
   if (head==NULL)
    return;
    cout<<head->data<<endl;
    print(head->right);
    print(head->left);
   }
        
     
     
     
  
  
  
  
  
  int main()
  {
     vector<int>v;
     v.push_back(-10);
     v.push_back(-3);
     v.push_back(0);
     v.push_back(5);
     v.push_back(9);
     
     Solution s;
     struct TreeNode* new_node = s.sortedArrayToBST(v);
     cout<<"Final display:"<<endl;
     print(new_node);
     
     return 0;
    }
