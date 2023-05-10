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

// function to delete all the nodes from the list
// that are greater than the specified value x
void deleteGreaterNodes(Node** head_ref, int x)
{
    Node *temp = *head_ref, *prev;
   
    // If head node itself holds the value greater than 'x'
    if (temp != NULL && temp->data > x) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        temp = *head_ref; // Change temp
    }
   
    // Delete occurrences other than head
    while (temp != NULL) {
   
        // Search for the node to be deleted,
        // keep track of the previous node as we
        // need to change 'prev->next'
        while (temp != NULL && temp->data <= x) {
            prev = temp;
            temp = temp->next;
        }
   
        // If required value node was not present
        // in linked list
        if (temp == NULL)
            return;
   
        // Unlink the node from linked list
        prev->next = temp->next;
   
        delete temp; // Free memory
   
        // Update Temp for next iteration of
        // outer loop
        temp = prev->next;
    }
}

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
