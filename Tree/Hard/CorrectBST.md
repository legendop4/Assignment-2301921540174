# Correct BST with Two Swapped Nodes - Solution

## Problem Link
[Correct BST with Two Swapped Nodes - GeeksforGeeks](https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1)

## Intuition
The problem requires identifying and correcting two nodes that have been swapped in a Binary Search Tree (BST). The key insights are:
1. In-order traversal of a BST produces a sorted sequence
2. Swapped nodes appear as violations in this sorted order
3. There are two cases: adjacent nodes swapped or non-adjacent nodes swapped

## Approach
1. **In-order Traversal**:
   - Perform in-order traversal while tracking the previous node
   - Identify nodes where current node's value is less than previous node's value
2. **Identify Swapped Nodes**:
   - First violation marks the first swapped node
   - Second violation marks the second swapped node
3. **Swap Values**:
   - Swap the values of the identified nodes to restore BST properties

## Solution Code
```cpp
// User function Template for C++

/*struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
public:
    void fixBST(Node* root, Node*& prev, Node*& first, Node*& second) {
        if(root == NULL)
            return;
            
        fixBST(root->left, prev, first, second);
        
        if(prev != NULL && root->data < prev->data) {
            if(first == NULL) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        
        fixBST(root->right, prev, first, second);
    }
    
    struct Node *correctBST(struct Node *root) {
        Node *prev = NULL, *first = NULL, *second = NULL;
        fixBST(root, prev, first, second);
        swap(first->data, second->data);
        return root;
    }
};
