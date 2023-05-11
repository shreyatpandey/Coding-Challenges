/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
*/
struct ListNode* deleteDuplicates(struct ListNode* head){
    
    /* Pointer to traverse the linked list */
    struct ListNode* current = head;
 
    /* Pointer to store the next pointer of a node to be
     * deleted*/
    struct ListNode* next_next;
 
    /* do nothing if the list is empty */
    if (current == NULL)
        return NULL;
 
    /* Traverse the list till last node */
    while (current->next != NULL) {
        /* Compare current node with next node */
        if (current->val == current->next->val) {
            /* The sequence of steps is important*/
            next_next = current->next->next;
            free(current->next);
            current->next = next_next;
        }
        else /* This is tricky: only advance if no deletion
              */
        {
            current = current->next;
        }
    }
    return head;
        
}
