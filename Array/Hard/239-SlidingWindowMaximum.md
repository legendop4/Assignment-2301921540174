# Sliding Window Maximum

**Problem Link**: [Sliding Window Maximum - LeetCode](https://leetcode.com/problems/sliding-window-maximum/)  
**Solution Link**: [Your Submission](https://leetcode.com/problems/sliding-window-maximum/submissions/1625338876)

## Intuition
The solution uses a **monotonic deque** (double-ended queue) to efficiently track the maximum element in each sliding window by maintaining elements in decreasing order and removing those outside the current window.

## Approach
1. **Deque Initialization**: 
   - Stores indices of elements in decreasing order of their values
   - Ensures the front always contains the current window's maximum

2. **Window Maintenance**:
   - Removes elements outside the current window (index < i-k+1)
   - Pops smaller elements from the back before adding new elements

3. **Result Collection**:
   - The front of the deque is added to the result for each window

## Complexity
- **Time Complexity**: O(n)  
  - Each element is pushed and popped from the deque at most once
- **Space Complexity**: O(k)  
  - The deque stores at most k elements

## Solution Code
```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove elements outside the current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            
            // Maintain decreasing order in deque
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            // Add to result once the first window is complete
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
