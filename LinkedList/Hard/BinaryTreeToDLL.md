# Binary Tree to Doubly Linked List - Solution

## Problem Link
[Binary Tree to DLL - GeeksforGeeks](https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1)

## Approach
The problem requires converting a binary tree to a doubly linked list in-place. The key insights are:
1. In-order traversal of BST gives nodes in sorted order
2. We need to maintain a previous pointer to build the DLL connections
3. The left pointer of DLL nodes should point to previous nodes
4. The right pointer of DLL nodes should point to next nodes

## Solution Code
```cpp
class Solution {
  public:
    Node* dummy = new Node(-1); // Dummy node to start the DLL
    Node* curr = dummy;         // Current pointer for building DLL
    
    // In-order traversal to process nodes
    void getData(Node* root) {
        if (root == nullptr) {
            return;
        }
        getData(root->left);
        
        // Create new DLL node and build connections
        Node* temp = new Node(root->data);
        curr->right = temp;
        temp->left = curr;
        curr = temp;
        
        getData(root->right);
    }

    // Main function to convert BST to DLL
    Node* bToDLL(Node* root) {
        getData(root);

        // Extract the head and remove dummy node connection
        Node* head = dummy->right;
        if (head != nullptr) {
            head->left = nullptr;
        }
        return head;
    }
};
