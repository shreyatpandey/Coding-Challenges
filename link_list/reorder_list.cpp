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
