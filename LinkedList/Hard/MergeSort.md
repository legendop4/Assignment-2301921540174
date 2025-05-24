# Sort Doubly Linked List using Merge Sort - Solution

## Problem
Given a doubly linked list, sort it using merge sort algorithm while maintaining the doubly linked structure.

## Approach
1. **Split**: Divide the list into two halves using slow-fast pointer technique
2. **Recursively Sort**: Sort each half separately
3. **Merge**: Combine the two sorted halves while maintaining the doubly linked structure

## Solution Code
```cpp
/* Structure of the node of the list is as */
class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
public:
    // Function to merge two sorted doubly linked lists
    Node* merge(Node* h1, Node* h2) {
        if (h1 == nullptr) return h2;
        if (h2 == nullptr) return h1;
        
        Node* result = nullptr;
        
        if (h1->data <= h2->data) {
            result = h1;
            result->next = merge(h1->next, h2);
            if (result->next) result->next->prev = result;
        } else {
            result = h2;
            result->next = merge(h1, h2->next);
            if (result->next) result->next->prev = result;
        }
        return result;
    }

    // Function to split the doubly linked list into two halves
    Node* split(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* secondHalf = slow->next;
        slow->next = nullptr;
        if (secondHalf) secondHalf->prev = nullptr;
        
        return secondHalf;
    }

    // Main function to sort the doubly linked list
    Node* sortDoubly(Node* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        Node* secondHalf = split(head);
        head = sortDoubly(head);
        secondHalf = sortDoubly(secondHalf);
        
        return merge(head, secondHalf);
    }
};
