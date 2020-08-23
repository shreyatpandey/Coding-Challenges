/*O(N) : Run-Time */
class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) {
        set<int>check_duplicate;
        ListNode* temp = head;
        ListNode* previous = NULL;
        while(temp)
        {
            if ( check_duplicate.find(temp->val) != check_duplicate.end())
            {
                previous->next = temp->next ;
                delete temp;
            }
            else
            {
                check_duplicate.emplace(temp->val);
                previous = temp;
            }
            temp = previous->next;
        }
        return head;
        
    }
};

/*O(N^2) : Run-Time */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL)
        {
            ListNode* previous = temp;
            while(previous && previous->next)
            {
                if(previous->next->val == temp->val)
                {
                    previous->next = previous->next->next;
                }
                else
                {
                    previous = previous->next;
                
                }
            }
            temp = temp->next;
        }
        return head;
    }
};
