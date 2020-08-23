/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        /*Not Using Set*/
      ListNode* dummy_node = new ListNode(0);
       dummy_node->next = head;
        ListNode* temp = dummy_node;
        while(temp->next !=NULL && temp->next->next != NULL)
        {
            if(temp->next->val == temp->next->next->val)
            {
                int duplicate = temp->next->val;
                while(temp->next != NULL && temp->next->val == duplicate)
                {
                    temp->next = temp->next->next;
                }
            }
            else
            {
                temp = temp->next;
            }
        }
        return dummy_node->next;
    }
};
