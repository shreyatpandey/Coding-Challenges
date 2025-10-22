// Find-Middle-Link-List.c
// Demonstrates finding the middle of a singly linked list using two pointers
// (slow and fast). For even-length lists the "standard" version below returns
// the second middle node. An alternative function returning the first middle
// is also provided.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
} Node;

// Create a new node with given value
static Node *create_node(int v) {
	Node *n = (Node *)malloc(sizeof(Node));
	if (!n) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	n->val = v;
	n->next = NULL;
	return n;
}

// Build a list from an array of ints. Returns head (NULL for size==0).
static Node *build_list(const int *arr, size_t n) {
	if (n == 0) return NULL;
	Node *head = create_node(arr[0]);
	Node *cur = head;
	for (size_t i = 1; i < n; ++i) {
		cur->next = create_node(arr[i]);
		cur = cur->next;
	}
	return head;
}

static void free_list(Node *head) {
	while (head) {
		Node *t = head->next;
		free(head);
		head = t;
	}
}

// Print list contents (small helper for tests)
static void print_list(Node *head) {
	for (Node *p = head; p; p = p->next) {
		printf("%d", p->val);
		if (p->next) printf(" -> ");
	}
	if (!head) printf("(empty)");
}

// Standard two-pointer approach. Returns the middle node.
// For even-length lists this returns the second middle node.
Node *find_middle(Node *head) {
	if (!head) return NULL;
	Node *slow = head;
	Node *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

// Alternative: return the first middle for even-length lists.
Node *find_middle_first(Node *head) {
	if (!head) return NULL;
	Node *slow = head;
	Node *fast = head->next; // start fast one step ahead
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

int main(void) {
	// Test cases: empty, single, two, three, four, five
	const int a0[] = {};
	const int a1[] = {1};
	const int a2[] = {1, 2};
	const int a3[] = {1, 2, 3};
	const int a4[] = {1, 2, 3, 4};
	const int a5[] = {1, 2, 3, 4, 5};

	struct { const int *arr; size_t n; } tests[] = {
		{a0, 0}, {a1, 1}, {a2, 2}, {a3, 3}, {a4, 4}, {a5, 5}
	};

	for (size_t i = 0; i < sizeof(tests)/sizeof(tests[0]); ++i) {
		Node *head = build_list(tests[i].arr, tests[i].n);
		printf("List %zu: ", i);
		print_list(head);
		Node *mid2 = find_middle(head);
		Node *mid1 = find_middle_first(head);
		printf("\n  Middle (standard, second for even): ");
		if (mid2) printf("%d", mid2->val); else printf("(none)");
		printf("\n  Middle (first for even): ");
		if (mid1) printf("%d", mid1->val); else printf("(none)");
		printf("\n\n");
		free_list(head);
	}

	return 0;
}

