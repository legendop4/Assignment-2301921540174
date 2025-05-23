# Convert Sorted Linked List to Balanced BST - Solution

## Problem Link
[GeeksforGeeks - Sorted List to BST](https://practice.geeksforgeeks.org/problems/sorted-list-to-bst/1)

## Approach
1. **Convert Linked List to Array**:
   - Traverse the linked list and store elements in a vector
2. **Recursive BST Construction**:
   - Use a divide-and-conquer approach to build the BST
   - Middle element becomes root
   - Left half forms left subtree
   - Right half forms right subtree

## Solution Code
```cpp
/*
struct LNode { //Linked List
    int data;
    struct LNode* next;
    LNode(int x){
        data = x;
        next = NULL;
    }
};
struct TNode {   //Tree
    int data;
    struct TNode* left;
    struct TNode* right;
    TNode(int x){
        data=x;
        left=right=NULL;
    }
}; */

class Solution {
public:
    TNode* dfs(vector<int>& container, int start, int end) {
        if(start >= end)
            return nullptr;
        int mid = (start + end)/2;
        TNode* node = new TNode(container[mid]);
        node->left = dfs(container, start, mid);
        node->right = dfs(container, mid+1, end);
        return node;
    }
    
    TNode* sortedListToBST(LNode* head) {
        vector<int> container;
        while(head) {
            container.push_back(head->data);
            head = head->
