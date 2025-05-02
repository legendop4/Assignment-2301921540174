# Intuition  
The problem requires checking if an array is "good" – meaning there exists a subset of elements whose linear combination equals 1. By Bézout's identity, this is true if and only if the greatest common divisor (GCD) of all elements is 1.

# Approach  
1. **Compute Overall GCD**: Iterate through the array while calculating the cumulative GCD of all elements.  
2. **Check Condition**: If the final GCD is 1, the array is good.  

# Complexity  
- **Time Complexity**: O(n \* log(max(nums))) – Each GCD computation takes O(log(max(a, b)) time for n elements.  
- **Space Complexity**: O(1) – Constant space for variables.  

# Problem and Solution Links  
- **Problem Link**: [Check If It Is a Good Array - LeetCode](https://leetcode.com/problems/check-if-it-is-a-good-array/)  
- **Solution Link**: [Submitted Solution](https://leetcode.com/problems/check-if-it-is-a-good-array/submissions/1623794110)  

# Code  
```cpp  
class Solution {
public:
    int gcdi(int a, int b) {
        if (b == 0) return a;
        return gcdi(b, a % b);
    }
    
    bool isGoodArray(vector<int>& nums) {
        int gcd_val = nums[0];
        for (int num : nums) {
            gcd_val = gcdi(gcd_val, num);
        }
        return gcd_val == 1;
    }
};
