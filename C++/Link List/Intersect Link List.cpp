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

/*Solution-2 */
class Solution {
    private:
        int count_length(ListNode* head)
        {
            int count_nodes = 0;
            ListNode* temp = head;
            while(temp != NULL)
            {
                count_nodes += 1;
                temp = temp->next;
            }
            return count_nodes;
        }
        ListNode *intersect_node_point(int difference,ListNode* head_one,ListNode* head_two)
        {
            ListNode *current_one = head_one;
            ListNode *current_two = head_two;
            for(int i=0;i<difference;i++)
            {
                current_one = current_one->next;
            }
            if (current_one == NULL)
            {
                return NULL;
            }
            while(current_one != NULL && current_two != NULL)
            {
                if ( current_one ==  current_two)
                    return current_one;
                current_one = current_one->next;
                current_two = current_two->next;
            }
            return NULL;
        }
        
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
        int length_list_one = count_length(headA);
        int length_list_two = count_length(headB);
        
        ListNode *intersect_node = length_list_one > length_list_two ? intersect_node_point(length_list_one - length_list_two,headA,headB) : intersect_node_point(length_list_two - length_list_one,headB,headA);
        
        if (intersect_node == NULL)
            return NULL;
        
        return intersect_node;

  }
   
};


