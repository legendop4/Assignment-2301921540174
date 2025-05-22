# 968. Binary Tree Cameras - Solution

## Problem Link
[968. Binary Tree Cameras - LeetCode](https://leetcode.com/problems/binary-tree-cameras/)

## Solution Link
[My Submission](https://leetcode.com/problems/binary-tree-cameras/submissions/1641495126)

## Intuition
The problem requires placing the minimum number of cameras on a binary tree nodes such that every node is monitored. The key insights are:
1. Cameras should be placed at strategic locations to cover maximum nodes
2. Nodes should be in one of three states: 
   - 0: Not covered
   - 1: Has camera
   - 2: Covered without camera
3. We can use post-order traversal to determine optimal camera placement

## Approach
1. **Post-order Traversal**:
   - Traverse left and right subtrees first
   - Determine the state of current node based on children's states
2. **State Management**:
   - If any child is not covered (0), place camera at current node
   - If any child has camera (1), current node is covered (2)
   - Otherwise, current node is not covered (0)
3. **Root Check**:
   - After traversal, check if root needs additional coverage

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
    int res = 0;
    
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + res;
    }
    
    int dfs(TreeNode* root) {
        if (!root) return 2;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        return (left == 1 || right == 1) ? 2 : 0;
    }
};
