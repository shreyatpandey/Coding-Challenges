/*Recursive-Solution */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
};

/*Iterative-Solution*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         ListNode* previous = NULL;
         ListNode* current = head;
         ListNode* temp;
        while(current != NULL)
        {
            temp = current->next ;
            current->next = previous;
            previous = current;
            current = temp;
            
            
        }
        head = previous;
        return head;
        
    }
};

