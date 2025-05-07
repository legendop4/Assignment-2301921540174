# Longest Valid Parentheses

**Problem Link**: [32. Longest Valid Parentheses - LeetCode](https://leetcode.com/problems/longest-valid-parentheses/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/longest-valid-parentheses/submissions/1627972650)

## Intuition
The solution uses a stack to track the indices of parentheses, allowing efficient calculation of the longest valid substring by:
1. Pushing indices of '(' onto the stack
2. Popping when encountering ')' to validate pairs
3. Calculating substring lengths using stack indices

## Approach
1. **Stack Initialization**:
   - Push -1 as base index for length calculation

2. **Iteration**:
   - For '(': Push current index
   - For ')':
     - Pop the stack
     - If stack becomes empty, push current index as new base
     - Else calculate current valid length (current index - stack top)

3. **Result Tracking**:
   - Maintain maximum valid length found

## Complexity
- **Time Complexity**: O(n)  
  - Single pass through the string
- **Space Complexity**: O(n)  
  - Stack storage in worst case (all '(')

## Solution Code
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0;
        stack<int> st;
        st.push(-1); // Base for length calculation
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(i);
            } 
            else {
                st.pop();
                if(st.empty()) {
                    st.push(i); // New base
                } 
                else {
                    max_len = max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};
