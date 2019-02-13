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
        void print_level_order(ListNode* root)
        {
            if (root == NULL)
                return;
            queue<ListNode*>input_node;
            input_node.push(root);
            while(!input_node.empty())
            {
                /*node count at current level*/
                int node_monitor = input_node.size();
                while( node_monitor)
                {
                    ListNode* present_node = input_node.front();
                    cout<<present_node->value<<" ";
                    input_node.pop();
                     if (present_node->left != NULL)
                        input_node.push(present_node->left);
                    if (present_node->right != NULL)
                        input_node.push(present_node->right);
                    node_monitor -= 1;
                    
                }
               cout<<endl;
                
            }
            
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
  s.print_level_order(temp);

    return 0;
}
