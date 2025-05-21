# 2509. Cycle Length Queries in a Tree - Solution

## Problem Link
[2509. Cycle Length Queries in a Tree - LeetCode](https://leetcode.com/problems/cycle-length-queries-in-a-tree/)

## Solution Link
[My Submission](https://leetcode.com/problems/cycle-length-queries-in-a-tree/submissions/1640526511)

## Intuition
The problem requires finding the length of the cycle formed when connecting two nodes in a perfect binary tree. The key insights are:
1. Each node's parent can be found by integer division by 2
2. The cycle length equals the sum of the distances from each node to their LCA plus 1
3. We can find the LCA by moving the deeper node up until both nodes meet

## Approach
1. For each query (u, v):
   - Initialize counters for both nodes
   - While u ≠ v:
     - Move the larger node up to its parent
     - Increment its counter
   - The cycle length is the sum of both counters plus 1 (for the connecting edge)

## Solution Code
```cpp
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& q) {
        vector<int> ans;
        for(int i = 0; i < q.size(); i++) {
            int x = q[i][0], y = q[i][1];
            int cx = 0, cy = 0;
            while(x != y) {
                if(x > y) {
                    cx++;
                    x = x / 2;
                } else {
                    cy++;
                    y = y / 2;
                }
            }
            ans.push_back(cx + cy + 1);
        }
        return ans;
    }
};
