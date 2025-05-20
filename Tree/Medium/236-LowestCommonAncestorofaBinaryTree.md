# Lowest Common Ancestor of a Binary Tree

**Problem Link**: [236. Lowest Common Ancestor of a Binary Tree - LeetCode](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/1639565968)

## Intuition
The solution finds the lowest common ancestor (LCA) of two nodes in a binary tree by:
1. Recursively searching both left and right subtrees
2. Checking if current node is either p or q
3. Determining LCA based on subtree search results

## Approach
1. **Base Case**:
   - If current node is null, p, or q, return the node
2. **Recursive Search**:
   - Search left and right subtrees
3. **LCA Determination**:
   - If both subtrees return non-null, current node is LCA
   - Otherwise, return the non-null subtree result

## Complexity
- **Time Complexity**: O(n)  
  - Visits each node once in worst case
- **Space Complexity**: O(h)  
  - Recursion stack height (h = tree height)
  - O(n) for skewed trees, O(log n) for balanced trees

## Solution Code
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q) {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if(left != nullptr && right != nullptr) {
            return root;
        }
        return left != nullptr ? left : right;
    }
};
