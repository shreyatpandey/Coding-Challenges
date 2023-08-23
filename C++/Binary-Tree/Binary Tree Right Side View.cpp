#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        rightView(root, view, 0);
        return view;
    }
private:
    void rightView(TreeNode* root, vector<int>& view, int level) {
        if (!root) {
            return;
        }
        if (view.size() == level) {
            view.push_back(root -> val);
        }
        rightView(root -> right, view, level + 1);
        rightView(root -> left, view, level + 1);
    }
};


 
/*
int main()
{   Solution s;
   struct TreeNode* temp = insert_node(1);
   temp->left = insert_node(2);
   temp->right = insert_node(3);
   temp->left->right = insert_node(5);
   temp->right->right = insert_node(4);
   
   vector<int>result = s.rightsideview(temp);
   cout<<"[";
    for(size_t i =0 ;i<result.size();i++)
   {
      cout<<result[i];
       if(!(i == result.size()-1))
       {
          cout<<",";
        }
     }
    cout<<"]";
    cout<<endl;
    return 0;
}
*/


