# N-Queens Problem Solution

**Problem Link**: [51. N-Queens - LeetCode](https://leetcode.com/problems/n-queens/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/n-queens/submissions/1626306814)

## Intuition
The solution uses backtracking to systematically place queens on an N×N chessboard such that no two queens threaten each other. It explores all possible configurations while ensuring the queens don't attack each other horizontally, vertically, or diagonally.

## Approach
1. **Board Initialization**: Create an empty N×N chessboard
2. **Backtracking**:
   - Try placing a queen in each column of the current row
   - Check if the position is safe (no conflicts)
   - Recursively proceed to the next row
   - Backtrack if no valid position is found
3. **Solution Collection**: When all N queens are placed safely, store the board configuration

## Complexity
- **Time Complexity**: O(N!)  
  - Worst-case scenario explores all possible permutations
- **Space Complexity**: O(N²)  
  - Storage for the chessboard and solutions
  - Recursion stack depth of N

## Solution Code
```cpp
class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column
        for(int i = 0; i < n; i++) {
            if(board[row][i] == 'Q') return false;
            if(board[i][col] == 'Q') return false;
        }
        
        // Check upper-left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        
        // Check upper-right diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        
        return true;
    }

    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < n; col++) {
            if(isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                nQueens(board, row + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        nQueens(board, 0, n, ans);
        return ans;
    }
};
