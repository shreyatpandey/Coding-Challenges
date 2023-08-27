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
        int length_link_list(ListNode* head)
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        if(head == NULL)
            return head;
        int length_link = length_link_list(head);
        int i=0;
            while(i<length_link/2)     
            {
               // cout<<"val:"<<temp->val;
                temp = temp->next;
                i++;
                
            }
            return temp;
    }
};

/*fast and slow pointer */
//TC:- O(N) where N is the length of link list
//SC:- O(1) as we are not adding any extra space

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
       ListNode* slow = head; 
      ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
           return slow;
    }
    };
