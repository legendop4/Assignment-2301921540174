# 889. Construct Binary Tree from Preorder and Postorder Traversal - Solution

## Problem Link
[889. Construct Binary Tree from Preorder and Postorder Traversal - LeetCode](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/)

## Solution Link
[My Submission](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/submissions/1639587811)

## Intuition
The key insight is that:
1. The first element in preorder is always the root
2. The next element in preorder is the root of the left subtree
3. We can find this left root's position in postorder to divide the tree into left and right subtrees

## Approach
1. **Base Case**: Return null if indices are out of bounds
2. **Root Creation**: First preorder element becomes the root
3. **Subtree Division**:
   - Find the left subtree root in postorder
   - Recursively build left and right subtrees using the found division point
4. **Termination**: Return the constructed root when done

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int index = 0;
        return construct(pre, post, index, 0, pre.size()-1);
    }
private:
    TreeNode* construct(vector<int>& pre, vector<int>& post, int& index, int l, int h) {
        if(index >= pre.size() || l > h) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(pre[index++]);
        if(l == h) return root;
        
        int i = l;
        while(i <= h && post[i] != pre[index]) i++;
        if(i <= h) {
            root->left = construct(pre, post, index, l, i);
            root->right = construct(pre, post, index, i+1, h-1);
        }
        return root;
    }
};
