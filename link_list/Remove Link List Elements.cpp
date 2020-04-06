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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        
      ListNode* temp = head;
        while(temp)
        {
            /*Remove Node */
            while(temp->next && temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        if (head && head->val == val)
        {
            head = head->next;
        }
        return head;
    }
};

/* Remove All Nodes greater than the input val */
struct ListNode {
      int val;
      ListNode *next;
  };
  struct ListNode* NewNode(int val)
  {
      struct ListNode* temp = new ListNode;
      temp->val = val;
      temp->next = NULL ;
      return temp;
      
  }
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return NULL;
        
      ListNode* temp = head;
        while(temp)
        {
            while(temp->next && temp->next->val > val)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }
        if (head && head->val > val)
        {
            head = head->next;
        }
        return head;
    }
};

int main()
{
    ListNode* head = NewNode ( 100);
    head->next = NewNode ( 160 );
    head->next->next = NewNode(105) ;
    head->next->next->next = NewNode(50) ;
    head->next->next->next->next = NewNode (150) ;

    Solution S;
    ListNode* result = S.removeElements(head,105);
    while(result != NULL)
    {
        cout<<result->val<<" ";
        result = result->next ;
    }
    cout<<endl;
    return 0;
}
