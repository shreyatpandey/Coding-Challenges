#include <stdlib.h>
#include <time.h>
#include <stdio.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct {
    struct ListNode* head;
} Solution;

Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = (Solution*)malloc(sizeof(Solution));
    obj->head = head;
    srand(time(NULL)); // Seed the random number generator
    return obj;
}

int solutionGetRandom(Solution* obj) {
    struct ListNode* current = obj->head;
    int result = current->val;
    int index = 1;

    while (current->next != NULL) {
        current = current->next;
        index++;
        if (rand() % index == 0) {
            result = current->val;
        }
    }

    return result;
}

void solutionFree(Solution* obj) {
    free(obj);
}

// Unit test cases
void testSolution() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    struct ListNode node5 = {5, NULL};
    struct ListNode node4 = {4, &node5};
    struct ListNode node3 = {3, &node4};
    struct ListNode node2 = {2, &node3};
    struct ListNode node1 = {1, &node2};

    // Create Solution object
    Solution* obj = solutionCreate(&node1);

    // Test solutionGetRandom
    printf("Random node values: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", solutionGetRandom(obj));
    }

    // Free Solution object
    solutionFree(obj);
}

int main() {
    testSolution();
    return 0;
}
