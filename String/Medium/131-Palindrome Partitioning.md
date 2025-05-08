# Palindrome Partitioning

**Problem Link**: [131. Palindrome Partitioning - LeetCode](https://leetcode.com/problems/palindrome-partitioning/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/palindrome-partitioning/submissions/1628634113)

## Intuition
The solution generates all possible palindrome partitions of a string using backtracking by:
1. Exploring all possible substrings starting at each index
2. Checking if the substring is a palindrome
3. Recursively processing the remaining string

## Approach
1. **Backtracking Framework**:
   - Start from each index in the string
   - Expand to find all palindromic substrings
   - Recurse on the remaining substring
   - Backtrack when a complete partition is found

2. **Palindrome Check**:
   - Helper function verifies if a substring is a palindrome
   - Uses two pointers moving towards the center

## Complexity
- **Time Complexity**: O(N × 2^N)  
  - In worst case, there are 2^N possible partitions
  - Each palindrome check takes O(N) time
- **Space Complexity**: O(N)  
  - Recursion stack depth (up to N)
  - Storage for current partition path

## Solution Code
```cpp
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        func(0, s, path, res);
        return res;
    }

    void func(int index, const string& s, vector<string>& path, vector<vector<string>>& res) {
        if(index == s.length()) {
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.length(); i++) {
            if(isPalin(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalin(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
