/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
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

