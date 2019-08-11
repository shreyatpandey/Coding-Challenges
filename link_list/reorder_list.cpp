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
    void reorderList(ListNode* head) {
      stack<ListNode*> store_node;
        ListNode *cur = head;
        int node_count = 0;
        
        if (head == nullptr)
            return;
        
        while (cur != nullptr) {
            node_count++;
            store_node.emplace(cur);
            cur = cur->next;
        }
        cur = head;
        for (int i = 0; i < node_count / 2; i++) {
            ListNode *next = cur->next;
            cur->next = store_node.top();
            store_node.top()->next = next;
            store_node.pop();
            cur = next;
        }
        cur->next = nullptr;
    }
};


//Approach-2
class Solution {
    private:
        ListNode* reverse_link_list(ListNode* start)
        {
            ListNode* current = start;
            ListNode* previous = NULL;
            ListNode* temp;
            while(current)
            {
                temp = current->next;
                current->next = previous;
                previous = current;
                current = temp;
            }
            start = previous;
            return start;
        }
public:
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* first_part = head;
        ListNode* second_part = slow->next;
        slow->next = NULL;
        second_part = reverse_link_list(second_part);
        ListNode* dummy_node = new ListNode(0);
        ListNode* temp = dummy_node;
        while(first_part || second_part)
        {
            if(first_part)
            {
                temp->next = first_part;
                temp = temp->next;
                first_part = first_part->next;
            }
            if(second_part)
            {
                temp->next = second_part;
                temp = temp->next;
                second_part = second_part->next;
            }
            
        }
        dummy_node = dummy_node->next;
        
        
    }
};
