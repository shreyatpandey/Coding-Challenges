/* Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Approach - 1
// TC:- O(n)
// SC:- O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head ;
        ListNode* temp = dummynode;
        while ( temp && temp->next && temp->next->next)
        {
            ListNode* first = temp ; //first is dummynode
            ListNode* second = temp->next; //second is head
            ListNode* third = temp->next->next;
            first->next = third;
            second->next = third->next;
            third->next  = second;
            temp = second;
        }
        return dummynode->next;
        
    }
};

