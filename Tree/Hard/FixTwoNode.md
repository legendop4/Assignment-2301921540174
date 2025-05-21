# Fix Two Nodes of a BST - Solution

## Problem Link
[Fix Two Nodes of a BST - GeeksforGeeks](https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1?page=1&category=Binary%20Search%20Tree,AVL-Tree&difficulty=Hard&sortBy=submissions)

## Intuition
The problem requires identifying and swapping two incorrectly placed nodes in a BST. The key insights are:
1. In-order traversal of a BST should produce a sorted sequence
2. Two swapped nodes will appear as anomalies in this sequence
3. We need to find these anomalies and swap the nodes back

## Approach
1. **In-order Traversal**:
   - Perform in-order traversal to identify nodes violating BST property
   - Track previous node during traversal for comparison
2. **Identify Anomalies**:
   - First anomaly occurs when previous node > current node
   - Second anomaly occurs at the next violation
3. **Swap Nodes**:
   - Swap the values of the identified nodes to restore BST properties

## Solution Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode *first, *middle, *last, *prev;
    
    void inorder(TreeNode* root) {
        if(!root) return;
        
        inorder(root->left);
        
        if(prev && root->val < prev->val) {
            if(!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;
        
        inorder(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        first = middle = last = prev = nullptr;
        inorder(root);
        
        if(first && last) {
            swap(first->val, last->val);
        } else if(first && middle) {
            swap(first->val, middle->val);
        }
    }
};
