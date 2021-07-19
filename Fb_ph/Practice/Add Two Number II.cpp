Q] What is the requirement of "prev_nine" node?
-> Previous_Nine node is required to take care of the edge cases:- [9,9,9,9] + [9,9,9]


Q] current_val:-
This is required to update the node for each sum. Basically you are creating new node for each value [ summation of each digits]

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
        ListNode* dummyNode = new ListNode(0);
        ListNode *prev_nine = NULL, *cur = dummyNode;
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
            cout<<"Total Value: "<<val<<" for i: "<<i<<endl;
            if (val > 9)
            {
                while (prev_nine != NULL && prev_nine != cur) //for edge case of [9,9,9,9] and [9,9,9]etc
                {
                    cout<<"prev_nine:"<<prev_nine->val<<endl;
                    prev_nine->val =  (prev_nine->val + 1) % 10;
                    prev_nine = prev_nine->next;
                }
                cout<<"cur->val_before:"<<cur->val<<endl;
                cur->val = (cur->val + 1) % 10; //understood this line as ( cur->val + 1 ) takes care of the previous carry
                cout<<"cur->val:"<<cur->val<<endl;
                prev_nine = (cur->val == 9) ? cur : NULL;
            }
            
            if (val % 10 == 9) //especially to take care of [9,9,9,9] and [9,9] where one of the them is bigger
                
            {
                cout<<"val%10 is hit"<<endl;
                prev_nine = prev_nine ? prev_nine : cur;
            
            }
            else
                prev_nine = NULL;
            //understood
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }
        
        ListNode* result = NULL;
        if (dummyNode->val != 0)
        { // this is especially for MSB to be 10 
            cout<<"dummyNode.val:"<<dummyNode->val<<endl;
            result = new ListNode(dummyNode->val);
            result->next = dummyNode->next;
        }
        else
            result = dummyNode->next;
        return result;
        
    }
};
