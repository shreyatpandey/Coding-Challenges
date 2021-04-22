/* Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Approach - 1
// TC:- O(n)
// SC:- O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummynode = new ListNode(0);
        dummynode->next = head ;
        ListNode* temp = dummynode;
        while ( temp && temp->next && temp->next->next)
        {
            ListNode* first = temp ; //first is dummynode
            ListNode* second = temp->next; //second is head
            ListNode* third = temp->next->next;
            first->next = third;
            second->next = third->next;
            third->next  = second;
            temp = second;
        }
        return dummynode->next;
        
    }
};

//Approach-2
//Faster than 100%
//TC:- O(n)
class Solution {
    ListNode* current = nullptr;
    ListNode* previous = nullptr;
    ListNode* dummynode = nullptr;
    ListNode* next = nullptr;
    void FindLengthLinkList(ListNode* head) ;
    int LengthLinkList = 0 ;
    int PairNode = 2;
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = head ;
        FindLengthLinkList(temp);
        dummynode = new ListNode(-1,nullptr);
        dummynode->next = head;
        previous = dummynode ;
        next,current = dummynode; 
        while(LengthLinkList>=PairNode)
        {
            current = previous->next ;
            next = current->next ;
            for(int i=1;i<PairNode;i++)
            {
                current->next = next->next ;
                next->next = previous->next ;
                previous->next = next ;
                next = current->next ;
            }
            previous = current ;
            LengthLinkList -= PairNode ;
        }
        return dummynode->next ;
    }
};
void Solution::FindLengthLinkList(ListNode* head)
{
    
    while(head)
    {
        head = head->next ;
        LengthLinkList += 1;
    }
}

