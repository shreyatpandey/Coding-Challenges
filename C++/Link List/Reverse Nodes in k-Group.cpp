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
//Iterative Solution
class Solution {
    private:
        ListNode *dummynode = NULL;
        ListNode* current = NULL;
        ListNode* next = NULL;
        ListNode* previous = NULL;
        int countnode = 0;
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) 
            return head;
        dummynode = new ListNode(0);
        dummynode->next = head;
        current = dummynode;
        next, previous = dummynode;
        while(current && current->next)  /*count the nodes */
        {  
            current = current->next;
            countnode++;
        }
        while(countnode>=k) 
        {
            current = previous->next;
            next = current->next;
            for(int i=1;i<k;++i) 
            {
                current->next=next->next;
                next->next=previous->next;
                previous->next=next;
                next=current->next;
            }
            previous = current;
            countnode -= k;
        }
        return dummynode->next;
        
    }
};
