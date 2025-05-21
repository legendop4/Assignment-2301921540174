# 297. Serialize and Deserialize Binary Tree - Solution

## Problem Link
[297. Serialize and Deserialize Binary Tree - LeetCode](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

## Solution Link
[My Submission](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/submissions/1640520402)

## Intuition
The problem requires converting a binary tree to a string representation (serialization) and reconstructing the tree from that string (deserialization). The key insights are:
1. Use level-order (BFS) traversal to capture the tree structure
2. Represent NULL nodes with a special character ('#')
3. Comma-separated values for easy parsing

## Approach
### Serialization:
1. Use BFS to traverse the tree level by level
2. Append node values or '#' for NULL nodes to the string
3. Separate values with commas

### Deserialization:
1. Parse the string using stringstream
2. Reconstruct the tree level by level using BFS
3. Create nodes for non-'#' values, maintain parent-child relationships

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curnode = q.front();
            q.pop();
            if(curnode == NULL) s.append("#,");
            else s.append(to_string(curnode->val)+',');
            if(curnode != NULL){
                q.push(curnode->left);
                q.push(curnode->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            } else {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            } else {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
