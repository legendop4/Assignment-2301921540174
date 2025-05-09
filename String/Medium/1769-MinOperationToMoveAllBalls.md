# Minimum Number of Operations to Move All Balls to Each Box

**Problem Link**: [1769. Minimum Number of Operations to Move All Balls to Each Box - LeetCode](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/submissions/1629502991)

## Intuition
The solution calculates the minimum operations to move all balls to each box by:
1. Performing a left-to-right pass to accumulate operations from the left
2. Performing a right-to-left pass to accumulate operations from the right
3. Combining both passes' results for each position

## Approach
1. **Left Pass**:
   - Track balls encountered and accumulated moves
   - For each box, store the sum of moves needed to bring left balls

2. **Right Pass**:
   - Similarly track balls and moves from the right
   - Add to the previously stored left pass values

3. **Result Construction**:
   - Each box's value is the sum of left and right operations

## Complexity
- **Time Complexity**: O(n)  
  - Two linear passes through the string
- **Space Complexity**: O(n)  
  - Output vector storage
  - Constant extra space for tracking

## Solution Code
```cpp
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.size(), 0);
        int balls = 0, moves = 0;
        
        // Left to right pass
        for(int i = 0; i < boxes.size(); i++) {
            ans[i] = balls + moves;
            moves += balls;
            balls += boxes[i] - '0';
        }
        
        balls = 0; moves = 0;
        // Right to left pass
        for(int i = boxes.size() - 1; i >= 0; i--) {
            ans[i] += balls + moves;
            moves += balls;
            balls += boxes[i] - '0';
        }
        
        return ans;
    }
};
