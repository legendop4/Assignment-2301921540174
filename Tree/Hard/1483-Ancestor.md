# 1483. Kth Ancestor of a Tree Node - Solution

## Problem Link
[1483. Kth Ancestor of a Tree Node - LeetCode](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/)

## Solution Link
[My Submission](https://leetcode.com/problems/kth-ancestor-of-a-tree-node/submissions/1641504582)

## Intuition
The problem requires efficiently finding the k-th ancestor of any node in a tree. The key insights are:
1. Naive approach (climbing one parent at a time) would be too slow for large k
2. Binary Lifting technique allows jumping in powers of two
3. Preprocessing parent information enables O(logk) queries

## Approach
1. **Binary Lifting Preprocessing**:
   - Create a 2D array P where P[i][j] represents 2^i-th ancestor of node j
   - Fill the array using dynamic programming: P[i][j] = P[i-1][P[i-1][j]]
2. **Query Processing**:
   - Decompose k into its binary representation
   - Make jumps in powers of two to reach the k-th ancestor
   - Return -1 if ancestor doesn't exist

## Solution Code
```cpp
class TreeAncestor {
public:
    vector<vector<int>> P; // P[i][j] = 2^i-th ancestor of j
    
    TreeAncestor(int n, vector<int>& parent) {
        P.resize(20, vector<int>(parent.size(), -1));
        
        // Initialize first parent (2^0 = 1)
        for(int i = 0; i < parent.size(); i++) {
            P[0][i] = parent[i];
        }
        
        // Binary Lifting preprocessing
        for(int i = 1; i < 20; i++) {
            for(int node = 0; node < parent.size(); node++) {
                int parent_node = P[i-1][node];
                if(parent_node != -1) {
                    P[i][node] = P[i-1][parent_node];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0; i < 20; i++) {
            if(k & (1 << i)) {
                node = P[i][node];
                if(node == -1) return -1;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node, k);
 */
