# Search in Rotated Sorted Array

**Problem Link**: [33. Search in Rotated Sorted Array - LeetCode](https://leetcode.com/problems/search-in-rotated-sorted-array/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/search-in-rotated-sorted-array/submissions/1625417318)

## Intuition
The solution efficiently searches a rotated sorted array using a modified binary search approach that determines which half of the array is properly sorted and adjusts the search range accordingly.

## Approach
1. **Binary Search Initialization**:
   - Set `start` to beginning and `end` to last index
   - Calculate `mid` index to divide search space

2. **Rotation Handling**:
   - If left half `[start..mid]` is sorted:
     - Check if target is within this range → search left
     - Else → search right
   - If right half `[mid..end]` is sorted:
     - Check if target is within this range → search right
     - Else → search left

3. **Termination**:
   - Return index if target found
   - Return -1 if target not found

## Complexity
- **Time Complexity**: O(log n)  
  - Standard binary search efficiency
- **Space Complexity**: O(1)  
  - Uses constant extra space

## Solution Code
```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
