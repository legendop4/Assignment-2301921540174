# Sudoku Solver

**Problem Link**: [LeetCode - Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)  
**Solution Link**: [My Submission](https://leetcode.com/problems/sudoku-solver/submissions/1624352655)

## Intuition
The solution uses a **backtracking** approach to systematically try all possible valid numbers for each empty cell ('.') until the entire board is filled correctly. It leverages constraint propagation to eliminate invalid choices early.

## Approach
1. **Backtracking Algorithm**:
   - Traverse the board to find empty cells
   - Try digits 1-9 in each empty cell
   - Check validity using row, column, and 3x3 sub-box constraints
   - Recursively attempt to solve the updated board
   - Backtrack if a path leads to an invalid solution

2. **Validation Checks**:
   - Row check: No duplicates in the current row
   - Column check: No duplicates in the current column
   - Sub-box check: No duplicates in the current 3x3 sub-grid

## Complexity
- **Time Complexity**: O(9^(n²)) in worst case  
  (Exponential time, but practically much faster due to constraint propagation)
- **Space Complexity**: O(n²)  
  (Recursion stack depth for the backtracking)

## Solution Code
```cpp
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) 
                                return true;
                            else 
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check row
            if (board[row][i] == c) return false;
            // Check column
            if (board[i][col] == c) return false;
            // Check 3x3 sub-box
            if (board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
        }
        return true;
    }
};
