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

