# Spiral Matrix IV

**Problem Link**: [2326. Spiral Matrix IV - LeetCode](https://leetcode.com/problems/spiral-matrix-iv/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/spiral-matrix-iv/submissions/1633067033)

## Intuition
The solution fills an m x n matrix in spiral order with values from a linked list by:
1. Simulating the spiral traversal (right → down → left → up)
2. Placing linked list values in each position
3. Filling remaining positions with -1 if the list is exhausted

## Approach
1. **Initialization**:
   - Create m x n matrix filled with -1
   - Set boundary pointers (top, bottom, left, right)

2. **Spiral Traversal**:
   - Right: Top row from left to right
   - Down: Right column from top+1 to bottom
   - Left: Bottom row from right-1 to left (if top ≤ bottom)
   - Up: Left column from bottom-1 to top (if left ≤ right)

3. **Termination**:
   - Stop when linked list is exhausted or boundaries cross

## Complexity
- **Time Complexity**: O(m × n)  
  - Each matrix cell visited exactly once
- **Space Complexity**: O(1) [excluding output]  
  - Constant space for boundary pointers
  - O(m × n) for the result matrix (required by problem)

## Solution Code
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        ListNode* curr = head;
        int top = 0, bottom = m-1, left = 0, right = n-1;
        
        while(curr != nullptr && top <= bottom && left <= right) {
            // Right
            for(int i = left; i <= right && curr != nullptr; i++) {
                res[top][i] = curr->val;
                curr = curr->next;
            }
            top++;
            
            // Down
            for(int i = top; i <= bottom && curr != nullptr; i++) {
                res[i][right] = curr->val;
                curr = curr->next;
            }
            right--;
            
            // Left (if needed)
            if(top <= bottom) {
                for(int i = right; i >= left && curr != nullptr; i--) {
                    res[bottom][i] = curr->val;
                    curr = curr->next;
                }
                bottom--;
            }
            
            // Up (if needed)
            if(left <= right) {
                for(int i = bottom; i >= top && curr != nullptr; i--) {
                    res[i][left] = curr->val;
                    curr = curr->next;
                }
                left++;
            }
        }
        return res;
    }
};
