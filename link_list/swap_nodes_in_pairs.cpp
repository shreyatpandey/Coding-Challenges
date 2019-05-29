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
    ListNode* swapPairs(ListNode* head) {
         if (!head || !head->next) return head;
        vector <ListNode*> res;
        ListNode* tmp;
        // push to result vector
        for(ListNode* node = head; node;node= node->next){
            res.push_back(node);
        }
        // swap 0 & 1 index value, 2 & 3, 4 & 5 ...... n-1 & n
        for(int i=0; i<res.size()-1; i=i+2){
            tmp = res[i];
            res[i] = res[i+1];
            res[i+1] = tmp;
        }
        // link lists to the next index node
        for(int i=0; i< res.size()-1; i++){
            res[i] -> next = res[i+1];
        }
        // set null for last node
        res[res.size()-1] -> next = nullptr;
        
        // return first node of the list
        return res[0];
    }
    
};
