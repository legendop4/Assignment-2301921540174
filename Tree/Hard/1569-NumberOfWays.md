# 1569. Number of Ways to Reorder Array to Get Same BST - Solution

## Problem Link
[1569. Number of Ways to Reorder Array to Get Same BST - LeetCode](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/)

## Solution Link
[My Submission](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/submissions/1641489024)

## Intuition
The problem requires counting the number of ways to reorder an array such that it forms the same BST structure as the original array. The key insights are:
1. The root must always be the first element
2. The relative order of elements in left and right subtrees must be preserved
3. We can use combinatorics to calculate the number of valid interleavings

## Approach
1. **Precompute Combinations**:
   - Build Pascal's triangle modulo 1e9+7 for quick combination calculations
2. **Recursive DFS**:
   - For each subtree, separate elements into left and right subtrees based on the root
   - Recursively calculate the number of valid orderings for each subtree
   - Combine results using the formula: C(n-1, k) * left_ways * right_ways
3. **Final Result**:
   - Subtract 1 to exclude the original ordering

## Solution Code
```cpp
class Solution {
public:
    vector<vector<long long>> table;
    
    long long dfs(vector<int>& nums, long long mod) {
        int n = nums.size();
        if (n <= 2) return 1;
        
        vector<int> left, right;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        
        long long left_res = dfs(left, mod) % mod;
        long long right_res = dfs(right, mod) % mod;
        int left_len = left.size(), right_len = right.size();
        
        return (((table[n - 1][left_len] * left_res) % mod) * right_res) % mod;
    }
    
    int numOfWays(vector<int>& nums) {
        long long mod = 1e9 + 7;
        int n = nums.size();
        
        // Build combination table using Pascal's triangle
        table.resize(n + 1);
        for (int i = 0; i < n + 1; i++) {
            table[i] = vector<long long>(i + 1, 1);
            for (int j = 1; j < i; j++) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
            }
        }
        
        long long ans = dfs(nums, mod);
        return (ans % mod - 1) % mod;
    }
};
