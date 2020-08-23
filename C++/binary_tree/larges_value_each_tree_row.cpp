#include <vector>
#include<algorithm>
#include<iostream>
#include<queue>
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
        vector<int>largestValues(ListNode* root)
        {
           vector<int>result;
          if(root == NULL)
            return result;
          
            queue<ListNode*>input_node;
            input_node.push(root);
           
            while(!input_node.empty())
            {
                vector<int>hold_values;
                /*node count at current level*/
                int node_monitor = input_node.size();
                while( node_monitor)
                {
                    ListNode* present_node = input_node.front();
                    hold_values.emplace_back(present_node->value);
                    input_node.pop();
                     if (present_node->left != NULL)
                        input_node.push(present_node->left);
                    if (present_node->right != NULL)
                        input_node.push(present_node->right);
                    node_monitor -= 1;
                    
                }
               int max_value_node = *max_element(hold_values.begin(),hold_values.end());
               result.emplace_back(max_value_node);
                
            }
            return result;
        }
    
        
};

int main()
{
    struct ListNode* temp = insert_node(1);
  temp->left = insert_node(3);
  temp->right = insert_node(2);
  temp->left->left = insert_node(5);
  temp->left->right = insert_node(3);
  temp->right->right = insert_node(9);
  Solution s;
  vector<int>hold_result = s.largestValues(temp);
  cout<<"[";
  for(int j=0;j<hold_result.size();j++)
  {

     cout<<hold_result[j];
     if (j!= hold_result.size() - 1)
     {
        cout<<",";
     }
      
  }
  cout<<"]";
    return 0;
}
