# Maximum Points After Collecting Coins from All Nodes - Solution

## Problem Link
[Maximum Points After Collecting Coins from All Nodes - LeetCode](https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes/)

## Solution Link
[My Submission](https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes/submissions/1641524995)

## Intuition
The problem requires maximizing points collected from tree nodes where we can either:
1. Collect coins with value `A[i] >> v` minus `k` penalty
2. Collect coins with value `A[i] >> (v + 1)` in the next step
The key insights are:
1. We need to explore both options at each node
2. The decision affects future node values through bit-shifting
3. Memoization helps avoid redundant calculations

## Approach
1. **Tree Construction**:
   - Build an adjacency list from the given edges
2. **DFS Traversal**:
   - For each node, calculate two options:
     - Option 1: Take current value (bit-shifted by `v`) minus `k`
     - Option 2: Take value bit-shifted by `v+1` in next step
3. **Memoization**:
   - Use a visited array to track computed states
   - Prune paths where the shift value exceeds 13 (since 2^14 > 1e4)

## Solution Code
```cpp
class Solution {
public:
    int vis[100001] = {};
    
    int dfs(int i, int p, vector<vector<int>> &G, vector<int> &A, int k, int v) {
        if(v > 13) return 0;
        if(vis[i] > v) return 0;
        
        int op1 = (A[i] >> v) - k;
        int op2 = A[i] >> (v + 1);
        
        vis[i]++;
        
        for(int j : G[i]) {
            if(j != p) {
                op1 += dfs(j, i, G, A, k, v);
                op2 += dfs(j, i, G, A, k, v + 1);
            }
        }
        
        return max(op1, op2);
    }
    
    int maximumPoints(vector<vector<int>>& edges, vector<int>& A, int k) {
        vector<vector<int>> G(edges.size() + 1);
        for(auto &e : edges) {
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]);
        }
        return dfs(0, -1, G, A, k, 0);
    }
};
