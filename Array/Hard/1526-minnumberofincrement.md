# Minimum Number of Increments on Subarrays to Form a Target Array

**Problem Link**: [LeetCode Problem](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/submissions/1626323229)

## Intuition
The solution efficiently calculates the minimum operations by recognizing that each increase in height from the previous element requires a new operation. This approach leverages the observation that adjacent operations can be combined when increasing subarrays.

## Approach
1. **Initialize**:
   - `prevheight` to track the previous element's value (starts at 0)
   - `opt` to accumulate the total operations

2. **Single Pass Calculation**:
   - For each element in `target`:
     - If current height > `prevheight`:
       - Add the difference to `opt` (new operations needed)
     - Update `prevheight` to current height

## Complexity
- **Time Complexity**: O(n)  
  - Single pass through the array
- **Space Complexity**: O(1)  
  - Uses only constant extra space

## Solution Code
```cpp
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int prevheight = 0;
        int opt = 0;
        for(int i = 0; i < target.size(); i++) {
            if(target[i] > prevheight) {
                opt += (target[i] - prevheight);
            }
            prevheight = target[i];
        }
        return opt;
    }
};
