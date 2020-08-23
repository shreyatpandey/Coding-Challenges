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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKListsHelper(lists, 0, lists.size() - 1);
        
    }
    private:
    ListNode *mergeKListsHelper(const vector<ListNode *> &lists, int begin, int end) {
        if (begin > end) {
            return NULL;
        }
        if (begin == end) {
            return lists[begin];
        }
        return mergeTwoLists(mergeKListsHelper(lists, begin, (begin + end) / 2),
                             mergeKListsHelper(lists, (begin + end) / 2 + 1, end));
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode{0};
        ListNode* curr = dummy;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;

        return dummy->next;
    }
};
