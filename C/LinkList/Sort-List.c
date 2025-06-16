#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    // Split the list into two halves
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mid = slow->next;
    slow->next = NULL;

    // Recursively sort both halves
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(mid);

    // Merge the sorted halves
    return merge(left, right);
}

ListNode* sortList(ListNode* head) {
    return mergeSort(head);
}

void printList(ListNode* head) {
    while (head) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

ListNode* createList(int* arr, int size) {
    ListNode* head = NULL;
    ListNode* tail = NULL;

    for (int i = 0; i < size; i++) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->val = arr[i];
        newNode->next = NULL;

        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    int arr[] = {4, 2, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createList(arr, size);

    printf("Original List: \n");
    printList(head);

    head = sortList(head);

    printf("Sorted List: \n");
    printList(head);

    return 0;
}
