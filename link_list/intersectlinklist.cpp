/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL && headB == NULL)
            return NULL;
        set<ListNode*>track_node;
        while(headA != NULL)
        {
            track_node.emplace(headA);
            headA = headA->next;   
        }
        while(headB != NULL)
        {
            if(track_node.find(headB) != track_node.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
        
    }
};


