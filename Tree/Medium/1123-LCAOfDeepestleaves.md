# Lowest Common Ancestor of Deepest Leaves - Solution

## Problem Link
[1123. Lowest Common Ancestor of Deepest Leaves - LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/)

## Solution Link
[My Submission](https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/submissions/1639594136)

## Intuition
The solution finds the lowest common ancestor (LCA) of the deepest leaves in a binary tree by:
1. Recursively calculating the depth of each subtree
2. Comparing depths of left and right subtrees
3. Determining the LCA based on subtree depths

## Approach
1. **Base Case**: If node is null, return depth 0 and null pointer
2. **Recursive Calls**: 
   - Get depth and LCA for left subtree
   - Get depth and LCA for right subtree
3. **Comparison**:
   - If depths are equal, current node is LCA
   - Otherwise, return LCA from deeper subtree
4. **Result**: The LCA of the deepest leaves is found at the root

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
    pair<int, TreeNode*> helper(TreeNode* node) {
        if(!node) return {0, nullptr};
        
        pair<int, TreeNode*> left = helper(node->left);
        pair<int, TreeNode*> right = helper(node->right);
        
        if(left.first == right.first)
            return {left.first + 1, node};
        else if(left.first > right.first)
            return {left.first + 1, left.second};
        else
            return {right.first + 1, right.second};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).second;
    }
};
