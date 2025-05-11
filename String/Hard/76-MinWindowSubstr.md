# Minimum Window Substring

**Problem Link**: [76. Minimum Window Substring - LeetCode](https://leetcode.com/problems/minimum-window-substring/)  
**Solution Link**: [Your Submission](https://leetcode.com/problems/minimum-window-substring/submissions/1631270867)

## Intuition
The solution finds the smallest substring in `s` that contains all characters of `t` using a sliding window approach:
1. Track character counts needed from `t`
2. Expand window to find valid substrings
3. Contract window from left to find minimum valid length

## Approach
1. **Initialization**:
   - Frequency map for characters in `t`
   - Track remaining characters needed (`targetchar`)
   - Window bounds tracking

2. **Sliding Window**:
   - Expand right pointer, decrement character counts
   - When all characters found (`targetchar == 0`):
     - Contract left pointer to minimize window
     - Update minimum window if smaller valid window found
     - Prepare to find next valid window

## Complexity
- **Time Complexity**: O(|S| + |T|)  
  - Single pass through `s` (|S|)
  - Single pass through `t` (|T|) for frequency map
- **Space Complexity**: O(1) or O(128)  
  - Fixed-size character frequency map

## Solution Code
```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        
        unordered_map<char, int> charcount;
        for(char ch : t) charcount[ch]++;
        
        int targetchar = t.length();
        int minWindow[2] = {0, INT_MAX};
        int startIndex = 0;
        
        for(int end = 0; end < s.length(); end++) {
            char ch = s[end];
            if(charcount.find(ch) != charcount.end() && charcount[ch] > 0) {
                targetchar--;
            }
            charcount[ch]--;
            
            if(targetchar == 0) {
                // Contract window from left
                while(true) {
                    char atstart = s[startIndex];
                    if(charcount.find(atstart) != charcount.end() && 
                       charcount[atstart] == 0) {
                        break;
                    }
                    charcount[atstart]++;
                    startIndex++;
                }
                
                // Update minimum window
                if(end - startIndex < minWindow[1] - minWindow[0]) {
                    minWindow[0] = startIndex;
                    minWindow[1] = end;
                }
                
                // Prepare for next window
                charcount[s[startIndex]]++;
                targetchar++;
                startIndex++;
            }
        }
        
        return minWindow[1] >= s.length() ? "" : 
               s.substr(minWindow[0], minWindow[1] - minWindow[0] + 1);
    }
};
