# Basic Calculator

**Problem Link**: [224. Basic Calculator - LeetCode](https://leetcode.com/problems/basic-calculator/)  
**Solution Link**: [Your Submission](https://leetcode.com/problems/basic-calculator/submissions/1631021214)

## Intuition
The solution evaluates mathematical expressions containing `+`, `-`, parentheses, and non-negative integers by:
1. Processing numbers digit-by-digit
2. Handling signs and parentheses using a stack
3. Accumulating results while respecting sign precedence

## Approach
1. **Initialization**:
   - Stack to manage sign changes from parentheses
   - Default sign is positive (1)
   - Variables to track current number and result

2. **Character Processing**:
   - Digits: Build multi-digit numbers
   - Signs: Apply current sign to number and reset
   - `(`: Push current sign context to stack
   - `)`: Pop sign context from stack

3. **Final Accumulation**:
   - Add last computed number to result

## Complexity
- **Time Complexity**: O(n)  
  - Single pass through the string
- **Space Complexity**: O(n)  
  - Stack depth scales with nested parentheses

## Solution Code
```cpp
class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int num = 0;
        int sign = 1;
        stack<int> st;
        st.push(sign);
        
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if(c == '+' || c == '-') {
                ans += sign * num;
                sign = st.top() * (c == '+' ? 1 : -1);
                num = 0;
            }
            else if(c == '(') {
                st.push(sign);
            }
            else if(c == ')') {
                st.pop();
            }
        }
        ans += sign * num;
        return ans;
    }
};
