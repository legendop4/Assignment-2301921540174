# Sort Colors (LeetCode 75)

## Problem Description
Given an array `nums` with elements `0` (red), `1` (white), and `2` (blue), sort them in-place without using library sort functions.

**Problem Link**: [Sort Colors - LeetCode](https://leetcode.com/problems/sort-colors/)

## Solution Approaches

### 1. Bubble Sort (Non-Optimal)
**Submission Link**: [Bubble Sort Solution](https://leetcode.com/problems/sort-colors/submissions/1624361752)

#### Approach
- Uses nested loops to repeatedly swap adjacent elements
- Gradually "bubbles" larger elements to the end

#### Complexity Analysis
- **Time**: O(n²) - Worst case requires complete pairwise comparisons
- **Space**: O(1) - Operates in-place
**Non optimal Approach :**
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < nums.size()-1-i; j++) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
};
```
# Optimal Solution: Dutch National Flag Algorithm

**Problem**: [Sort Colors - LeetCode](https://leetcode.com/problems/sort-colors/)  
**Submission**: [Optimal Solution](https://leetcode.com/problems/sort-colors/submissions/1624361168)

## Approach
### Three-Way Partitioning
- Uses three pointers to maintain partitions:
  - `low` → tracks the boundary of 0's
  - `mid` → scans the array and processes 1's
  - `high` → tracks the boundary of 2's
- Single-pass operation with in-place swaps

## Complexity
- **Time**: O(n) → Processes each element exactly once  
- **Space**: O(1) → Uses only constant extra space

## Solution Code
```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            switch (nums[mid]) {
                case 0:  // Current element is 0
                    swap(nums[low++], nums[mid++]);
                    break;
                case 1:  // Current element is 1
                    mid++;
                    break;
                case 2:  // Current element is 2
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};
