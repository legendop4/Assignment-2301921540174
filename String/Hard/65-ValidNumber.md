# Valid Number

**Problem Link**: [65. Valid Number - LeetCode](https://leetcode.com/problems/valid-number/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/valid-number/submissions/1627995748)

## Intuition
The solution validates if a string represents a number by systematically checking:
1. Digit presence (required)
2. Sign positions (only after 'e/E' or at start)
3. Decimal point rules (only one, not after 'e/E')
4. Exponent rules (only one, must follow digits)

## Approach
1. **State Tracking**:
   - `num`: At least one digit exists
   - `isdot`: Decimal point encountered
   - `ise`: Exponent encountered

2. **Character Validation**:
   - Digits: Always valid
   - Signs: Only valid after 'e/E' or at start
   - 'e/E': Must follow digits, only one allowed
   - '.': Only one allowed, not after exponent

3. **Final Check**:
   - Must have at least one digit

## Complexity
- **Time Complexity**: O(n)  
  - Single pass through the string
- **Space Complexity**: O(1)  
  - Uses only boolean flags

## Solution Code
```cpp
class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool isdot = false, num = false, ise = false;
        
        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                num = true;
            }
            else if(s[i] == '+' || s[i] == '-') {
                if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')) 
                    return false;
            }
            else if(s[i] == 'e' || s[i] == 'E') {
                if(ise || !num) return false;
                ise = true;
                num = false; // Reset for exponent part
            }
            else if(s[i] == '.') {
                if(isdot || ise) return false;
                isdot = true;
            }
            else {
                return false;
            }
        }
        return num;
    }
};
