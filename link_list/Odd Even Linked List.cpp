/*
Given a singly linked list, group all odd nodes together followed by the even nodes.
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
*/
class Solution {
    private :
        ListNode* odd_node = NULL;
        ListNode* even_node = NULL;
        ListNode* evenhead_node = NULL;
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return NULL;
        odd_node = head;
        even_node = head->next;
        evenhead_node = even;
        while(even_node != NULL && even_node->next != NULL)
        {
            odd_node->next = even_node->next;
            odd_node = odd_node->next;
            even_node->next = odd_node->next;
            even_node = even_node->next;
        }
        odd_node->next = evenhead_node;
        return head;
    }
};
