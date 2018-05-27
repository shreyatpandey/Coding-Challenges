#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
  int value;
  struct ListNode* right;
  struct ListNode* left;
};
struct ListNode* insert_node(int data)
{
  struct ListNode* temp = new ListNode;
  temp->value = data;
  temp->right=NULL;
  temp->left=NULL;
  return temp;
};

class Solution
{
  public:
   vector<double>averageofLevel(ListNode* root)
   {
      vector<double>result;
      queue<ListNode*>q; 
      q.push(root);
      while(!q.empty())
      {
        size_t sum=0,count=0;
        queue<ListNode*>temp;
        while(!q.empty())
        {
         ListNode* N = q.front();
         q.pop();
         sum = sum + N->value;
         count+=1;
         if(N->left!=NULL)
         temp.push(N->left);
         if(N->right!=NULL)
         temp.push(N->right);
         }
        q=temp;
        result.push_back(sum*1.0/count);
       }
      return result;
    }
};




int main()
{
  struct ListNode* temp = insert_node(3);
  temp->left = insert_node(9);
  temp->right = insert_node(20);
  temp->right->left = insert_node(15);
  temp->right->right = insert_node(7);
  Solution s;
  vector<double>result_hold;
  vector<double>::iterator it;
  result_hold = s.averageofLevel(temp);
  cout<<"Average_Binary_tree"<<endl;
  cout<<"[";
  for(it=result_hold.begin();it!=result_hold.end();++it)
  {
    cout<<(*it);
    if(it != result_hold.end()-1)
     {
       cout<<",";
      }
  }
  cout<<"]"<<endl;
  return 0;
}
