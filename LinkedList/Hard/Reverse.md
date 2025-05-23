# Reverse Linked List Between Positions - Solution

## Problem
Reverse a linked list from position `a` to position `b` (1-based indexing)

## Approach
1. **Initialization**:
   - Create a dummy node to handle edge cases when reversing starts from head
   - Move to the node just before position `a` (first)
2. **Reversal**:
   - Initialize pointers for reversal (prev, curr, front)
   - Reverse nodes between `a` and `b` by adjusting pointers
3. **Reconnection**:
   - Connect the reversed portion back to the original list
   - Handle special case when reversal starts from head (a=1)

## Solution Code
```cpp
// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/
class Solution {
public:
    Node* reverseBetween(int a, int b, Node* head) {
        int A = a;
        int B = b;
        Node* first = new Node(0); // Dummy node
        first->next = head;
        A--;
        
        // Move to node before position a
        while(A) {
            first = first->next;
            A--;
        }
        
        Node* prev = first;
        Node* curr = first->next;
        Node* second = curr; // Will be the tail of reversed portion
        Node* front = nullptr;
        int x = b - a + 1; // Number of nodes to reverse
        
        // Reverse the portion between a and b
        while(x) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
            x--;
        }
        
        // Reconnect the reversed portion
        first->next = prev;
        second->next = curr;
        
        // Handle case when reversing starts from head
        if(a == 1) {
            head = prev;
        }
        
        return head;
    }
};
