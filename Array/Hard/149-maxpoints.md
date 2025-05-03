# Max Points on a Line

**Problem Link**: [LeetCode - Max Points on a Line](https://leetcode.com/problems/max-points-on-a-line/)  
**Solution Link**: [Your Submission](https://leetcode.com/problems/max-points-on-a-line/submissions/1624329849)

## Intuition
To determine the maximum number of points lying on the same straight line by:
- Comparing every pair of points
- Calculating their slopes
- Grouping points with identical slopes relative to a reference point

## Approach
1. **Edge Case Handling**:
   - If there are ≤ 2 points, return the count directly (all points are collinear)
   
2. **Slope Calculation**:
   - For each reference point `i`:
     - Initialize a hashmap to track slope frequencies
     - Count duplicate points separately
   - For every other point `j`:
     - Handle vertical lines (infinite slope)
     - Compute slope for non-vertical lines
     - Update slope frequency in hashmap

3. **Result Computation**:
   - Maximum points = highest slope count + duplicates + reference point

## Complexity
- **Time Complexity**: O(n²)  
  - Nested loops comparing all point pairs
- **Space Complexity**: O(n)  
  - Hashmap stores at most n slope entries

## Solution Code
```cpp
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() <= 2) return points.size();
        int res = 1;
        
        for (int i = 0; i < points.size(); i++) {
            unordered_map<double, int> umap;
            int duplicates = 0;
            int curmax = 0;
            
            for (int j = i + 1; j < points.size(); j++) {
                // Handle duplicate points
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
                    duplicates++;
                    continue;
                }
                
                // Calculate slope
                double slope;
                if (points[i][0] == points[j][0]) {
                    slope = numeric_limits<double>::infinity();
                } else {
                    slope = (double)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                }
                
                umap[slope]++;
                curmax = max(curmax, umap[slope]);
            }
            
            res = max(res, curmax + duplicates + 1);
        }
        
        return res;
    }
};
