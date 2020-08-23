/* From CTCI */
/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5*/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_start  = NULL;
        ListNode* before_end = NULL;
        ListNode* after_start = NULL;
        ListNode* after_end = NULL;
        
        while(head)
    {
            ListNode* temp = head->next;
            head->next = NULL; //whats the need of this
            if(head->val < x)
            {
                if(before_start == NULL)
                {
                    before_start = head;
                    before_end = before_start; //both will point to head now
                }
                else
                {
                    before_end->next = head; //this order is important, output differs
                    before_end = head;
                }
            
            }
            else
            {
                if(after_start == NULL)
                {
                    after_start = head;
                    after_end = after_start;
                }
                else
                {
                    after_end->next = head;
                    after_end = head;
                }
            
            }
            head = temp;
        
        }
        if(before_start == NULL)
            return after_start;
        
        before_end->next = after_start;
        return before_start;
        
    }

};
