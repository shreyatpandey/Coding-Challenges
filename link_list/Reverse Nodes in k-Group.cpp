/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //Recursive Solution
class Solution 
{
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    int counter = k;
        ListNode* nextheadmonitor = head;
        while (counter > 0 && nextheadmonitor)
        {
            nextheadmonitor = nextheadmonitor->next;
            counter--;
        }
        if (counter > 0)
        {
            return head;
        }
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* temp = NULL;
        while (current != nextheadmonitor)
        {
            temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        head->next = reverseKGroup(nextheadmonitor, k);
        return previous;
        
    }
};
