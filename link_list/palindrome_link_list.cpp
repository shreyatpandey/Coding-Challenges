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
        int length_link_list (ListNode* head)
        {
            int count_nodes = 0;
            while(head)
            {
                count_nodes += 1;
                head = head->next; 
            }
            return count_nodes;
        }
        
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        ListNode* temp = head;
        int length_of_link_list = length_link_list(temp);
        vector<int>link_list_values;
        temp = head;
        while(temp)
        {
            link_list_values.emplace_back(temp->val);
            temp = temp->next;
        }
        for(int i = 0;i<length_of_link_list/2;i++)
        {
           
            if(link_list_values[i] != link_list_values[length_of_link_list - i - 1])
                return false;
        }
        return true;
    }
       
};

/* Approach-2 */
class Solution 
{     
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
        stack<int>st;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL) /* case for fast->next != NULL, if not used would fail for [1] single element link list */
        {
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        /* if odd number of element, skip the middle element */
        if ( fast != NULL)
        {
            slow = slow->next;
        }
        while ( slow != NULL)
        {
            int temp = st.top();
            st.pop();
            if (temp != slow->val)
                return false;
            slow = slow->next;
        }
        return true;
        
    }
};
