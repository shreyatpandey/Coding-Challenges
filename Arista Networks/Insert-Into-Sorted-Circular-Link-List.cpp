#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a Node.
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
