# Gas Station Problem

**Problem Link**: [134. Gas Station - LeetCode](https://leetcode.com/problems/gas-station/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/gas-station/submissions/1626338927)

## Intuition
The solution determines if there's a starting gas station that allows circular travel by:
1. Checking if total gas can cover total cost (feasibility check)
2. Tracking cumulative gas surplus to identify the optimal starting point

## Approach
1. **Initialization**:
   - `totgas` and `totcost` for feasibility check
   - `curgas` tracks current gas surplus
   - `start` marks potential starting station

2. **Single Pass**:
   - Accumulate total gas and cost
   - Update current gas surplus
   - Reset starting point when gas runs negative

3. **Feasibility Check**:
   - If total gas ≥ total cost, return `start`
   - Else return -1 (no solution)

## Complexity
- **Time Complexity**: O(n)  
  - Single pass through the array
- **Space Complexity**: O(1)  
  - Uses only constant extra space

## Solution Code
```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0, totcost = 0;
        int curgas = 0, start = 0;
        
        for(int i = 0; i < gas.size(); i++) {
            totgas += gas[i];
            totcost += cost[i];
            curgas += gas[i] - cost[i];
            
            if(curgas < 0) {
                start = i + 1;
                curgas = 0;
            }
        }
        return (totgas >= totcost) ? start : -1;
    }
};
