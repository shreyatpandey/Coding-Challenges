#include <iostream>
#include <functional> // Required for std::function and std::less

// Define a simple Node structure for our linked list
template <typename T>
struct Node {
    T data;
    Node<T>* next;

    Node(T val) : data(val), next(nullptr) {}
};

// Function to print a linked list (for testing purposes)
template <typename T>
void printList(Node<T>* head) {
    Node<T>* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
}

// Function to merge two sorted linked lists using a template and a comparator
template <typename T, typename Comparator = std::less<T>>
Node<T>* mergeSortedLists(Node<T>* l1, Node<T>* l2, Comparator comp = Comparator()) {
    // Base cases
    if (l1 == nullptr) {
        return l2;
    }
    if (l2 == nullptr) {
        return l1;
    }

    Node<T>* result = nullptr;
    Node<T>* tail = nullptr; // To keep track of the last node in the merged list

    // Determine the head of the merged list
    if (comp(l1->data, l2->data)) {
        result = l1;
        l1 = l1->next;
    } else {
        result = l2;
        l2 = l2->next;
    }
    tail = result;

    // Iterate through both lists and append to the merged list
    while (l1 != nullptr && l2 != nullptr) {
        if (comp(l1->data, l2->data)) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next; // Move the tail to the newly added node
    }

    // Append remaining nodes (if any)
    if (l1 != nullptr) {
        tail->next = l1;
    } else if (l2 != nullptr) {
        tail->next = l2;
    }

    return result;
}

// Custom comparator for descending order
template <typename T>
struct DescendingComparator {
    bool operator()(const T& a, const T& b) const {
        return a > b; // For descending order, 'a' is "less" if it's greater than 'b'
    }
};

int main() {
    // --- Example 1: Merging integers in ascending order (default comparator) ---
    std::cout << "--- Merging Integers (Ascending Order) ---" << std::endl;
    Node<int>* l1_int = new Node<int>(1);
    l1_int->next = new Node<int>(3);
    l1_int->next->next = new Node<int>(5);

    Node<int>* l2_int = new Node<int>(2);
    l2_int->next = new Node<int>(4);
    l2_int->next->next = new Node<int>(6);

    std::cout << "List 1 (int): ";
    printList(l1_int);
    std::cout << "List 2 (int): ";
    printList(l2_int);

    Node<int>* merged_int = mergeSortedLists(l1_int, l2_int);
    std::cout << "Merged List (int): ";
    printList(merged_int);
    std::cout << std::endl;
    return 0;
}