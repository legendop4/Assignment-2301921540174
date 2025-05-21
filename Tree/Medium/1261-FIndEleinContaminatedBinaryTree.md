# 1261. Find Elements in a Contaminated Binary Tree - Solution

## Problem Link
[1261. Find Elements in a Contaminated Binary Tree - LeetCode](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/)

## Solution Link
[My Submission](https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/submissions/1639601770)

## Intuition
The problem requires recovering values in a binary tree that was contaminated (all values set to -1) and then efficiently answering queries about whether specific values exist in the recovered tree. The key insights are:
1. The root value is always 0
2. Child nodes follow the pattern: left = 2*parent + 1, right = 2*parent + 2
3. We can recover all values and store them in a hash set for O(1) lookups

## Approach
1. **Initialization**:
   - Set root value to 0
   - Initialize a hash set to store all recovered values
2. **Tree Recovery**:
   - Recursively traverse the tree
   - For each node, calculate its children's values using the given formula
   - Store all values in the hash set
3. **Find Operation**:
   - Simply check if the target exists in the hash set

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
class FindElements {
    unordered_set<int> recoveredValues;
    
    void recoverTree(TreeNode* root) {
        if(!root) return;
        recoveredValues.insert(root->val);
        if(root->left) {
            root->left->val = 2 * root->val + 1;
            recoverTree(root->left);
        }
        if(root->right) {
            root->right->val = 2 * root->val + 2;
            recoverTree(root->right);
        }
    }
    
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        recoverTree(root);
    }
    
    bool find(int target) {
        return recoveredValues.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
