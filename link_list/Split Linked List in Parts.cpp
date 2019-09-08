/*Given a (singly) linked list with head node root, write a function to split the linked list into k consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. 
This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]
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
    protected:
        ListNode* current = NULL;
        int node_count = 0;
        int width = 0;
        int remainder = 0;
        int count_node(ListNode* head);
        
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        current = root;
        vector<ListNode*>result(k,NULL);
        node_count = count_node(root);
        width =node_count/k;
        remainder = node_count % k;
        for(int i =0;i<k;++i)
        {
            ListNode* head = new ListNode(0);
            ListNode* write = head;
            for (int j = 0; j < width + (i < remainder ? 1 : 0); ++j) 
            {
                write->next = new ListNode(current->val);
                write = write->next;
                if (current)
                    current = current->next;
            }
            result[i] = head->next;
        }
        
        
        return result;
        
        
    }
};
int Solution::count_node(ListNode* head)
{
    ListNode* temp = head;
    int n = 0;
    while(temp)
    {
        temp = temp->next;
        n += 1;
    }
    return n;
}
