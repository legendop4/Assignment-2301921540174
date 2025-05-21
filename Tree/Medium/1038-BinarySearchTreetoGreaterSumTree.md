# 1038. Binary Search Tree to Greater Sum Tree - Solution

## Problem Link
[1038. Binary Search Tree to Greater Sum Tree - LeetCode](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/)

## Solution Link
[My Submission](https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/submissions/1639603978)

## Intuition
The problem requires converting a BST to a Greater Sum Tree (GST) where each node's value is replaced by the sum of all nodes with values greater than or equal to itself. The key insight is:
1. Performing a reverse in-order traversal (right-root-left) allows us to accumulate the sum of greater values
2. We can modify node values in-place during this traversal

## Approach
1. **Reverse In-order Traversal**:
   - Traverse the right subtree first (greater values)
   - Update the running sum and current node's value
   - Traverse the left subtree (smaller values)
2. **Sum Accumulation**:
   - Maintain a global sum variable
   - For each node, add its original value to the sum
   - Replace the node's value with the current sum

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
public:
    int sum = 0;
    
    void traverse(TreeNode* root) {
        if(root) {
            traverse(root->right);
            sum += root->val;
            root->val = sum;
            traverse(root->left);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        traverse(root);
        return root;
    }
};
