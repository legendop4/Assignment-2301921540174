# Trapping Rain Water II (3D Elevation Map)

**Problem Link**: [Trapping Rain Water II - LeetCode](https://leetcode.com/problems/trapping-rain-water-ii/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/trapping-rain-water-ii/submissions/1625406945)

## Intuition
The solution uses a **min-heap priority queue** to simulate the water trapping process from the boundaries inward, calculating how much water can be trapped at each cell based on the lowest surrounding boundary height.

## Approach
1. **Initialize Boundaries**:
   - Mark all boundary cells as visited
   - Push boundary heights into a min-heap

2. **Process Cells**:
   - Extract the smallest height from the heap (current boundary)
   - Check its 4-directional neighbors
   - Calculate trapped water (`max(0, boundary_height - current_height)`)
   - Push the new boundary (max of current height and neighbor height) into the heap

3. **Repeat** until all cells are processed

## Complexity
- **Time Complexity**: O(MN log(MN))  
  - Each cell is processed once (O(MN))
  - Heap operations take O(log(MN)) per insertion/extraction
- **Space Complexity**: O(MN)  
  - For the visited matrix and priority queue storage

## Solution Code
```cpp
class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
        int n = height.size();
        int m = height[0].size();
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> vis(n, vector<int>(m));

        // Push boundary cells into the heap
        for(int i = 0; i < n; i++) {
            vis[i][0] = vis[i][m-1] = 1;
            pq.push({height[i][0], {i, 0}});
            pq.push({height[i][m-1], {i, m-1}});
        }

        for(int j = 0; j < m; j++) {
            vis[0][j] = vis[n-1][j] = 1;
            pq.push({height[0][j], {0, j}});
            pq.push({height[n-1][j], {n-1, j}});
        }

        int ans = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!pq.empty()) {
            auto [h, pos] = pq.top();
            auto [r, c] = pos;
            pq.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc]) {
                    ans += max(0, h - height[nr][nc]);
                    pq.push({max(h, height[nr][nc]), {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};
