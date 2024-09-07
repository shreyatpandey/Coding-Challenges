/*
Given a Circular Linked List node, which is sorted in ascending order, 
write a function to insert a value insertVal into the list such that it remains a sorted circular list. 
The given node can be a reference to any single node in the list and may not necessarily be the smallest value in the circular list.

If there are multiple suitable places for insertion, you may choose any place to insert the new value. 
After the insertion, the circular list should remain sorted.

If the list is empty (i.e., the given node is null), you should create a new single circular list and return the reference to that single node.
Otherwise, you should return the originally given node.

*/

//TC:- O(n)
//SC:- O(1)

// Definition for a Node.
/*
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/
Node* AddNodeToEmpty (Node*head,int val)
{
    Node* temp = new Node(val);
    temp->next = temp;
    return temp;
};
class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if ( head == nullptr)
            return AddNodeToEmpty(head,insertVal);
        Node* temp, *p;
        p = head;
        temp = head->next;
        do
        {
            if ( p->val <=insertVal && insertVal <=temp->val)
            {
                p->next = new Node(insertVal,temp);
                return head;
            }
            else if ( p->val > temp->val)
            {
                if ( insertVal>=p->val || insertVal <= temp->val )
                {
                    p->next = new Node(insertVal,temp);
                    return head;
                }
            }
            p = temp;
            temp = temp->next;
        } while ( temp != head->next);
    p->next = new Node(insertVal,temp);
    return head;
}
};

