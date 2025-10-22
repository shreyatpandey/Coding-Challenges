
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Iterative merge of two sorted lists (LeetCode 21 signature)
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *dummy = malloc(sizeof *dummy);
    if (!dummy) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    dummy->next = NULL;
    struct ListNode *tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // attach the remaining part
    tail->next = (l1 != NULL) ? l1 : l2;

    struct ListNode *head = dummy->next;
    free(dummy);
    return head;
}

// Helper: create a linked list from an array, returns head (or NULL)
struct ListNode* create_list_from_array(int *arr, size_t n) {
    if (n == 0) return NULL;
    struct ListNode *head = NULL, *tail = NULL;
    for (size_t i = 0; i < n; ++i) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        if (!node) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        node->val = arr[i];
        node->next = NULL;
        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

// Helper: print list values
void print_list(struct ListNode *head) {
    struct ListNode *cur = head;
    while (cur) {
        printf("%d", cur->val);
        if (cur->next) printf(" -> ");
        cur = cur->next;
    }
    printf("\n");
}

// Helper: free list nodes
void free_list(struct ListNode *head) {
    while (head) {
        struct ListNode *next = head->next;
        free(head);
        head = next;
    }
}

// Example main (not executed per request). This demonstrates usage.
int main(void) {
    int a1[] = {1, 2, 4};
    int a2[] = {1, 3, 4};
    struct ListNode *l1 = create_list_from_array(a1, sizeof(a1)/sizeof(a1[0]));
    struct ListNode *l2 = create_list_from_array(a2, sizeof(a2)/sizeof(a2[0]));

    struct ListNode *merged = mergeTwoLists(l1, l2);
    print_list(merged); // expected: 1 -> 1 -> 2 -> 3 -> 4 -> 4

    free_list(merged);
    return 0;
}

