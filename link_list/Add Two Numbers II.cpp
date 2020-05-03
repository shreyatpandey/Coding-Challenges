/*
You are given two non-empty linked lists representing two non-negative integers. 
The most significant digit comes first and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
*/


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
        int length_link_list(ListNode* input)
        {
            int length_link = 0;
            while(input)
            {
                length_link += 1;
                input = input->next;
            }
            return length_link;
        }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int length_l1 = length_link_list(l1);
        int length_l2 = length_link_list(l2);
        int max_length = max(length_l1,length_l2);
        ListNode dummyNode(0);
        ListNode *prev_nine = NULL, *cur = &dummyNode;
        for (size_t i = 0; i < max_length; ++i){
            int val = 0;
            if ((max_length - i) <= length_l1)
            {
                val += l1->val;
                l1 = l1->next;
            }
            
            if ((max_length - i) <= length_l2)
            {
                val += l2->val;
                l2 = l2->next;
            }
            
            if (val > 9)
            {
                while (prev_nine != NULL && prev_nine != cur)
                {
                    prev_nine->val =  (prev_nine->val + 1) % 10;
                    prev_nine = prev_nine->next;
                }
                
                cur->val = (cur->val + 1) % 10;
                prev_nine = (cur->val == 9) ? cur : NULL;
            
            } 
            if (val % 10 == 9)
            {  
                prev_nine = prev_nine ? prev_nine : cur;
            }
             else
                prev_nine = NULL;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }
        
        ListNode* result = NULL;
        if (dummyNode.val != 0){
            result = new ListNode(dummyNode.val);
            result->next = dummyNode.next;
        }
        else
            result = dummyNode.next;
        return result;
        
    }
};
