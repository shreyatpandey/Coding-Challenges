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
