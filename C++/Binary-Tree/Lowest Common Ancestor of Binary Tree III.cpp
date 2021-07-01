/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        int p_d = depth(p);
        int q_d = depth(q);
        cout<<"p_d:"<<p_d<<endl;
        cout<<"q_d:"<<q_d<<endl;
        while (p_d > q_d) {
            p = p->parent;
            --p_d;
        }
        while (p_d < q_d) {
            q = q->parent;
            --q_d;
        }
        cout<<"p_d now:"<<p_d<<endl;
        cout<<"q_d now:"<<q_d<<endl;
        while (p != q) {
            p = p->parent;
            q = q->parent;
        }
        return p;
    }

private:
    int depth(Node *node) {
        int d = 0;
        while (node) {
            node = node->parent;
            ++d;
        }
        return d;
    }
};
