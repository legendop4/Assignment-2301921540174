# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
The problem requires finding the maximum sum of a contiguous subarray within a given array of integers. The optimal approach leverages Kadane's algorithm, which efficiently tracks the maximum subarray sum by maintaining a running sum and resetting it when it becomes negative.

# Approach
<!-- Describe your approach to solving the problem. -->
1.**Initialization:** Start with max_sum set to the smallest possible value to handle arrays with all negative numbers. Initialize current_sum to 0 to accumulate the sum of the current subarray.

2.**Iteration:** Traverse each element in the array, adding the current element to current_sum.

3.**Update Maximum Sum:** After each addition, check if current_sum exceeds max_sum. If it does, update max_sum.

4.**Reset Current Sum:** If current_sum becomes negative, reset it to 0. This ensures that any subsequent subarrays start fresh, as a negative sum cannot contribute positively to future sums.
# Complexity
- **Time complexity:** O(n), where n is the number of elements in the array. The algorithm performs a single pass through the array.

<!-- Add your time complexity here, e.g. $$O(n)$$ -->

<!-- Add your space complexity here, e.g. $$O(n)$$ -->
- **Space complexity:** O(1), as only a constant amount of extra space is used for variables.
# Code
```cpp []
class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        long long max = LONG_MIN;
        long long sum = 0;
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            sum += arr[i];
            
            if(sum>max){
                max = sum;
            }
            
            if(sum<0){
                sum = 0;
            }
        }
        return max;
    }
};
```
