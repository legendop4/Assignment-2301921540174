# Find Unique Binary String

**Problem Link**: [1980. Find Unique Binary String - LeetCode](https://leetcode.com/problems/find-unique-binary-string/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/find-unique-binary-string/submissions/1631089905)

## Intuition
The solution generates a unique binary string by exploiting the diagonalization principle:
1. Construct a string where the i-th bit differs from the i-th bit of the i-th string in the input
2. Guarantees the result differs from every string in the input list

## Approach
1. **String Construction**:
   - For each position i in the result string:
     - Flip the i-th bit of the i-th input string
   - This ensures the result differs from every input string in at least one position

## Complexity
- **Time Complexity**: O(n)  
  - Single pass through the input strings (n = number of strings)
- **Space Complexity**: O(n)  
  - Storage for the result string

## Solution Code
```cpp
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res = "";
        for(int i = 0; i < nums.size(); i++) {
            res += nums[i][i] == '0' ? '1' : '0';
        }
        return res;
    }
};
