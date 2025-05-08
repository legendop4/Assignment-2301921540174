# Palindrome Partitioning II

**Problem Link**: [132. Palindrome Partitioning II - LeetCode](https://leetcode.com/problems/palindrome-partitioning-ii/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/palindrome-partitioning-ii/submissions/1628651444)

## Intuition
The solution calculates the minimum cuts needed to partition a string into palindromic substrings using dynamic programming:
1. Precompute palindrome substrings
2. Use DP to store minimum cuts from each position to end
3. Return the minimum cuts for the entire string

## Approach
1. **Initialization**:
   - DP array of size n+1 initialized to 0
   - Base case: dp[n] = 0 (empty string needs no cuts)

2. **DP Calculation**:
   - For each position i from end to start:
     - Find all palindromic substrings starting at i
     - Update dp[i] with minimum cuts needed

3. **Result Extraction**:
   - Return dp[0] - 1 (adjustment for initial count)

## Complexity
- **Time Complexity**: O(N³)  
  - N² for DP states
  - N for palindrome check per state
- **Space Complexity**: O(N)  
  - DP array storage

## Solution Code
```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[n] = 0;
        
        for(int i = n-1; i >= 0; i--) {
            int minCost = INT_MAX;
            for(int j = i; j < n; j++) {
                if(isPalin(s, i, j)) {
                    int cost = 1 + dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }

    bool isPalin(string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
