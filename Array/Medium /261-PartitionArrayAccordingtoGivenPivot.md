# Intuition  
The problem requires partitioning an array around a pivot value such that elements less than the pivot come first, followed by elements equal to the pivot, and then elements greater than the pivot. The optimal approach uses a two-pointer technique to efficiently group elements without sorting.

# Approach  
1. **Two-Pointer Strategy**:  
   - Use `left` and `right` pointers to track positions for elements less than and greater than the pivot.  
   - Iterate through the array from both ends simultaneously.  
2. **First Pass**:  
   - Place elements less than the pivot at the `left` pointer (incrementing `left`).  
   - Place elements greater than the pivot at the `right` pointer (decrementing `right`).  
3. **Fill Middle**:  
   - After processing all elements, fill the remaining positions between `left` and `right` with the pivot value.  

# Complexity  
- **Time Complexity**: O(n) – Single pass through the array.  
- **Space Complexity**: O(n) – Output array of size `n`.  

# Problem and Solution Links  
- **Problem Link**: [Partition Array According to Given Pivot - LeetCode](https://leetcode.com/problems/partition-array-according-to-given-pivot)  
- **Solution Link**: [Submitted Solution](https://leetcode.com/problems/partition-array-according-to-given-pivot/submissions/1623823047)  

# Code  
```cpp  
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int left = 0, right = n - 1;
        vector<int> ans(n);
        
        // Process elements from both ends
        for (int i = 0, j = n - 1; i < n; i++, j--) {
            if (nums[i] < pivot) { // Place smaller elements at left
                ans[left++] = nums[i];
            }
            if (nums[j] > pivot) { // Place larger elements at right
                ans[right--] = nums[j];
            }
        }
        
        // Fill remaining positions with pivot
        while (left <= right) {
            ans[left++] = pivot;
        }
        return ans;
    }
};
