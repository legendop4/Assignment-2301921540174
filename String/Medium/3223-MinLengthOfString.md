# Minimum Length of String After Operations

**Problem Link**: [3223. Minimum Length of String After Operations](https://leetcode.com/problems/minimum-length-of-string-after-operations/description/)

**Solution Link**: [My Submission](https://leetcode.com/problems/minimum-length-of-string-after-operations/submissions/1627999738)

## Intuition
The solution attempts to calculate the minimum possible string length after operations by:
1. Counting character frequencies
2. Determining if characters can be fully removed in pairs
3. Summing remaining single characters

## Approach
1. **Frequency Count**:
   - Initialize a frequency array for 26 letters
   - Count occurrences of each character

2. **Length Calculation**:
   - For each character:
     - Even counts contribute 0 (can be fully removed)
     - Odd counts contribute 1 (one remains)

## Complexity
- **Time Complexity**: O(n)  
  - One pass for frequency counting
  - One pass through 26 letters
- **Space Complexity**: O(1)  
  - Fixed-size frequency array (26 elements)

## Solution Code
```cpp
class Solution {
public:
    int minimumLength(string s) {
        vector<int> freq(26, 0);
        int tl = 0;
        
        // Count character frequencies
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        // Calculate remaining length
        for (int fre : freq) {
            if (fre == 0) continue;
            if (fre % 2 == 0) {
                tl += 2;
            } else {
                tl += 1;
            }
        }
        return tl;
    }
};
