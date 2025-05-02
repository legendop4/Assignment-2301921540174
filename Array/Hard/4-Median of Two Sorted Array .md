# Intuition

The problem requires finding the median of two sorted arrays efficiently without merging them. The optimal approach uses binary search on the smaller array to partition both arrays such that the left elements are less than or equal to the right elements. This ensures the median can be directly determined from the partition.

# Approach

1. **Ensure Smaller Array First**: Swap the arrays if necessary to perform binary search on the smaller array, optimizing the time complexity.

2. **Binary Search Setup**: Initialize binary search bounds (`low` and `high`) on the smaller array. Compute `left` as the required number of elements in the left partition of the combined arrays.

3. **Partition Adjustment**: In each iteration, compute partition points (`mid1` and `mid2`) and determine the maximum elements on the left (`l1`, `l2`) and minimum on the right (`r1`, `r2`).

4. **Check Valid Partition**: If the left elements are all <= right elements, compute the median based on total elements' parity. Adjust the binary search bounds if the partition is invalid.

5. **Edge Handling**: Use `INT_MIN` and `INT_MAX` to handle cases where partitions are at the boundaries of the arrays.

# Complexity

- **Time Complexity**: O(log(min(n, m))), where n and m are the lengths of the two arrays. Binary search is applied on the smaller array.

- **Space Complexity**: O(1), as only a constant amount of extra space is used.

# Problem and Solution Link
- **Problem Link** : [Problem Link ](https://leetcode.com/problems/median-of-two-sorted-arrays/)
- **Solution Link** : [Solution Link](https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1623066217 )
# Code

```cpp

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int low = 0,high = n1;
        int left = (n1+n2+1)/2;
        int n = n1+n2;
        while(low<= high){
            int mid1 = (low+high)/2;
            int mid2 = left - mid1;
            int l1 = INT_MIN,l2 = INT_MIN;
            int r1 = INT_MAX,r2 = INT_MAX;
            if(mid1<n1)
                r1 = nums1[mid1];
            if(mid2<n2)
                r2 = nums2[mid2];
            if(mid1-1>=0)
                l1 = nums1[mid1-1];
            if(mid2-1>=0)
                l2 = nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2 ==1) return max(l1,l2);
                return(double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2)
                high = mid1-1;
            else 
                low = mid1+1; 

        }
        return 0;
    }
};

```
