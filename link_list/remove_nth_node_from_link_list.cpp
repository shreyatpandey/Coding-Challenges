/*Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.*/




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    private:
        int find_length_link_list(ListNode* head)
        {
            int length_link_list = 0;
            while(head != NULL)
            {
                length_link_list += 1;
                head = head->next;
            }
            return length_link_list;
        }
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n)
        {
            int length = find_length_link_list(head);
            if(length - n == 0)
            {
                head = head->next; 
                return head;
            }
            int new_length = length - n;
            ListNode* temp = head;
            int i =0;
            while(i<new_length-1)
            {
                i ++;
                temp = temp->next;
            }
            temp->next = temp->next->next;
            return head;    
            
        }
};
