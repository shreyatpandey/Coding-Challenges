class Solution {
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
