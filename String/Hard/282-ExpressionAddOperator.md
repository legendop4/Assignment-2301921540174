# Expression Add Operators

**Problem Link**: [282. Expression Add Operators - LeetCode](https://leetcode.com/problems/expression-add-operators/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/expression-add-operators/submissions/1629483908)

## Intuition
The solution generates all possible expressions by inserting operators (+, -, *) between digits of the input string and evaluates them to match the target. It uses backtracking to:
1. Explore all possible number groupings
2. Try all operator combinations
3. Handle multiplication precedence correctly using residual values

## Approach
1. **Backtracking Framework**:
   - Build expressions recursively
   - Track current value and residual for multiplication
   - Handle number grouping (no leading zeros)

2. **Operator Handling**:
   - Addition: Simply add the new number
   - Subtraction: Subtract the new number
   - Multiplication: Adjust using residual to maintain precedence

3. **Base Case**:
   - When entire string is processed, check if evaluation matches target

## Complexity
- **Time Complexity**: O(4^N)  
  - At each step, 3 operator choices (+, -, *) plus concatenation
  - N = length of input string
- **Space Complexity**: O(N)  
  - Recursion stack depth
  - Storage for current path

## Solution Code
```cpp
class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string s, int target) {
        helper(s, target, 0, "", 0, 0);
        return ans;
    }
    
    void helper(string s, int target, int i, string path, long eval, long residual) {
        if(i == s.length()) {
            if(eval == target) {
                ans.push_back(path);
            }
            return;
        }
        
        string curstr;
        long num = 0;
        for(int j = i; j < s.length(); j++) {
            // Handle leading zero
            if(j > i && s[i] == '0') break;
            
            curstr += s[j];
            num = num * 10 + (s[j] - '0');
            
            if(i == 0) {
                // First number, no operator
                helper(s, target, j + 1, curstr, num, num);
            } else {
                // Try all operators
                helper(s, target, j + 1, path + "+" + curstr, eval + num, num);
                helper(s, target, j + 1, path + "-" + curstr, eval - num, -num);
                helper(s, target, j + 1, path + "*" + curstr, eval - residual + residual * num, residual * num);
            }
        }
    }
};
