# Intuition  
The problem requires determining how many people each person in a queue can see to their right. The optimal approach uses a **monotonic stack** to track decreasing heights, allowing efficient visibility checks by processing elements from right to left.

# Approach  
1. **Right-to-Left Iteration**: Start from the end of the array to leverage the stack's properties.  
2. **Monotonic Stack**:  
   - For each person, pop shorter people from the stack (they are visible).  
   - If the stack isn't empty after popping, the current person can also see the next taller/equal person.  
3. **Count Visible People**: Track visibility counts using stack operations.  

# Complexity  
- **Time Complexity**: O(n) – Each element is pushed/popped from the stack exactly once.  
- **Space Complexity**: O(n) – Worst-case stack storage for `n` elements.  

# Problem and Solution Links  
- **Problem Link**: [Number of Visible People in a Queue - LeetCode](https://leetcode.com/problems/number-of-visible-people-in-a-queue)  
- **Solution Link**: [Submitted Solution](https://leetcode.com/problems/number-of-visible-people-in-a-queue/submissions/1623767661)  

# Code  
```cpp  
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& height) {
        int n = height.size();
        stack<int> st; // Monotonic stack (decreasing order)
        vector<int> ans(n, 0);
        
        // Iterate from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop shorter people (visible to current person)
            while (!st.empty() && height[i] > st.top()) {
                st.pop();
                ans[i]++;
            }
            // Account for next taller/equal person (if exists)
            if (!st.empty()) ans[i]++;
            st.push(height[i]); // Add current height to stack
        }
        return ans;
    }
};
