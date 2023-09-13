/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

//TC:- O(n)
//SC:- O(h)
class Solution {
    private:
        Node * prev = NULL;
        void InOrder(Node* root);
public:
    Node* treeToDoublyList(Node* root) {
        if ( !root )
            return NULL;
        Node* dummy = new Node(0,NULL,NULL);
        prev = dummy;
        InOrder(root);
        
        prev->right = dummy->right;
        dummy->right->left = prev;
        return dummy->right;
    }
};

void Solution::InOrder(Node* root)
{
    if ( !root ) return ;
    InOrder(root->left);
    prev->right = root;
    root->left = prev;
    prev = root;
    InOrder(root->right);
}
