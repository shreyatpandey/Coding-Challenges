/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807
*/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        int sum = 0;
        int carry = 0;
        ListNode* current = result;
        while(l1 || l2)
        {
            int x = (l1?l1->val:0);
            int y = (l2?l2->val:0);
            sum = carry + x + y;
            carry = sum/10;
            current->next = new ListNode(sum%10);
            current = current->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry>0)
            current->next = new ListNode(carry);
        return result->next;
    }
};

