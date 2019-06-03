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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        
      ListNode* temp = head;
        while(temp)
        {
            /*Remove Node */
            while(temp->next && temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        if (head && head->val == val)
        {
            head = head->next;
        }
        return head;
    }
};
