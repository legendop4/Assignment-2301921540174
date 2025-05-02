# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem requires finding the smallest missing positive integer in an unsorted array. Two approaches are presented:
1. Non-Optimal (Hashing): Use a frequency array to track which positive integers exist in the range [1, n].
2. Optimal (In-Place Hashing): Rearrange elements in-place using cyclic sorting to position positive integers at their corresponding indices (x at index x-1).
# Approach
<!-- Describe your approach to solving the problem. -->
**Non-Optimal (Hashing) :**
1. **Frequency Array:** Create an array of size n+1 to track occurrences of integers in [1, n].
2. **Mark Presence:** Iterate through the input array and mark indices in the frequency array.
3. **Find Missing:** Scan the frequency array for the first unmarked index (missing positive).

**Optimal (In-Place Hashing) :**
1. **Cyclic Sort:** Iterate through the array and place each valid positive integer x (where 1 ≤ x ≤ n) at index x-1 via swapping.
2. **Find Mismatch:** After rearrangement, the first index i where nums[i] ≠ i+1 gives the missing positive.
  
# Complexity

<!-- Add your time complexity here, e.g. $$O(n)$$ -->
**Non-Optimal (Hashing) :**
- Time Complexity: O(n) – Two linear scans.
- Space Complexity: O(n) – Extra frequency array of size n+1.

**Optimal (In-Place Hashing) :**
- Time Complexity: O(n) – Each element is processed at most twice.
- Space Complexity: O(1) – In-place rearrangement.

# Problem and Solution Links
**Problem Link:** [First Missing Positive - LeetCode](https://leetcode.com/problems/first-missing-positive/)

**Non-Optimal Solution:** [Hashing Approach](https://leetcode.com/problems/first-missing-positive/submissions/1623029095/)

**Optimal Solution:** [In-Place Hashing](https://leetcode.com/problems/first-missing-positive/submissions/1623038952/)

# Code
**Non-Optimal Solution :**
```cpp []
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n + 1, 0); // Frequency array
        
        // Mark presence of valid positive integers
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= n) {
                ans[nums[i]]++;
            }
        }
        
        // Find the first missing positive
        for (int i = 1; i <= n; i++) {
            if (ans[i] == 0) {
                return i;
            }
        }
        
        return n + 1; // All [1, n] are present
    }
};
```
**Optimal Solution :**
```cpp []
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Cyclic sort to place elements in their correct positions
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Find the first mismatch between index and value
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1; // All [1, n] are present
    }
};
```
