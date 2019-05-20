/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy_node = new ListNode(0);
        ListNode* tail = dummy_node;
        while(l1!=NULL and l2!=NULL)
        {
            if(l1->val<= l2->val)
            {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
                
            }
            else
            {
                tail->next = l2;
                tail = tail->next;
                l2 = l2->next;       
            }
        }
        if(l1!=NULL)
        {
            while(l1)
            {
                tail->next = l1;
                tail = tail->next;
                l1 = l1->next;
            }
        }
        else
        {
            while(l2)
            {
               tail->next = l2;
               tail = tail->next;
               l2 = l2->next;  
            }
        }
        return dummy_node->next;
    }
};
