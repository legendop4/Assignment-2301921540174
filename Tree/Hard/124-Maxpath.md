# 124. Binary Tree Maximum Path Sum - Solution

## Problem Link
[124. Binary Tree Maximum Path Sum - LeetCode](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

## Solution Link
[My Submission](https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/1641512529)

## Intuition
The problem requires finding the maximum path sum in a binary tree where a path is defined as any sequence of nodes connected by edges. The key insights are:
1. A path can include at most one "turn" (where left and right subtrees meet)
2. We need to consider both straight paths (single branch) and paths with turns
3. Negative contributions from subtrees should be discarded (treated as 0)

## Approach
1. **Post-order Traversal**:
   - Traverse left and right subtrees first
   - Calculate maximum path sums for each subtree
2. **Path Calculation**:
   - For each node, compute two values:
     - The maximum straight path sum (for parent nodes)
     - The maximum path sum with turn (for global maximum)
3. **Result Update**:
   - Keep track of the global maximum path sum
   - Return the maximum straight path sum to parent nodes

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
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* node, int& res) {
        if (!node) {
            return 0;
        }
        
        // Calculate maximum path sums from left and right subtrees
        // Discard negative sums (treat as 0)
        int leftSum = max(0, dfs(node->left, res));
        int rightSum = max(0, dfs(node->right, res));
        
        // Update global maximum with path that includes current node as root
        res = max(res, leftSum + rightSum + node->val);
        
        // Return maximum straight path sum (for parent nodes)
        return max(leftSum, rightSum) + node->val;
    }
};
