# 1028. Recover a Tree From Preorder Traversal - Solution

## Problem Link
[1028. Recover a Tree From Preorder Traversal - LeetCode](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/)

## Solution Link
[My Submission](https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/submissions/1640505924)

## Intuition
The problem requires reconstructing a binary tree from its preorder traversal string with dash-count representing depth. The key insights are:
1. The number of dashes before a value indicates its depth in the tree
2. We need to track both the current position in the string and the expected level
3. Nodes are added as left children first, then right children

## Approach
1. **Initialization**:
   - Create a dummy root node
   - Initialize index and level tracking variables
2. **Recursive Construction**:
   - Parse numbers and dashes from the string
   - When dashes match expected level, create new node
   - Attach as left child if available, otherwise as right child
   - Recursively build subtrees with increased level
3. **Termination**:
   - Return the actual root (left child of dummy node)

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
    string s;
    int idx = 0, lvl = 0;
    
    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        TreeNode* dummy = new TreeNode(-1);
        helper(dummy, 0);
        return dummy->left;  
    }

    void helper(TreeNode* parent, int current_lvl) {
        while (idx < s.length() && lvl == current_lvl) {
            int num = 0;
            while (idx < s.length() && isdigit(s[idx])) {
                num = num * 10 + (s[idx++] - '0');
            }
            TreeNode* node = new TreeNode(num);
            if (!parent->left) {
                parent->left = node;
            } else {
                parent->right
