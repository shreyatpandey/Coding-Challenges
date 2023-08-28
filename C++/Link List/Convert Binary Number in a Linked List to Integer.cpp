/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//TC:- O(N) where N is the length of Link List
//SC:- O(1)

class Solution {
    private:
        ListNode* ReverseLinkList(ListNode* head);
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        head = ReverseLinkList(temp);
        int i = 0;
        int decimalresult  = 0;
        while ( head != NULL)
        {
            decimalresult += (pow(2,i)*head->val) ;
            i += 1;
            head = head->next;
        }
        return decimalresult;
        
    }
};
ListNode* Solution:: ReverseLinkList(ListNode* head)
{
    ListNode* current = head;
    ListNode* previous = NULL;
    ListNode* temp ;
    while(current != NULL)
    {
        temp = current->next;
        current->next = previous;
        previous = current ;
        current = temp;
    }
    head = previous ;
    return head;
}
//TC:- O(N) where N is the lenght of the link list
//No reverse is required
//SC:- O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = head->val;
        while(head->next != NULL)
        {
            num = num*2 + head->next->val;
            head = head->next;
        }
        return num;
    }
};
