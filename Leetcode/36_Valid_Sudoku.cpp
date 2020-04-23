// 36. Valid Sudoku
// Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

// Example 1:
// Input:
// [
//   ["5","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: true

// Example 2:
// Input:
// [
//   ["8","3",".",".","7",".",".",".","."],
//   ["6",".",".","1","9","5",".",".","."],
//   [".","9","8",".",".",".",".","6","."],
//   ["8",".",".",".","6",".",".",".","3"],
//   ["4",".",".","8",".","3",".",".","1"],
//   ["7",".",".",".","2",".",".",".","6"],
//   [".","6",".",".",".",".","2","8","."],
//   [".",".",".","4","1","9",".",".","5"],
//   [".",".",".",".","8",".",".","7","9"]
// ]
// Output: false

// Explanation: Same as Example 1, except with the 5 in the top left corner being 
//     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
// The given board contain only digits 1-9 and the character '.'.
// The given board size is always 9x9.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                int count = 0;
                if(board[i][j] == '.'){
                    continue;
                }
                for(int k = j; k < 9; ++k){
                    if(board[i][j] == board[i][k]){
                        count++;
                    }
                    if(count > 1){
                        return false;
                    }
                }
            }
        }
        for(int j = 0; j < 9; ++j){
            for(int i = 0; i < 9; ++i){
                int count = 0;
                if(board[i][j] == '.'){
                    continue;
                }
                for(int k = i; k < 9; ++k){
                    if(board[i][j] == board[k][j]){
                        count++;
                    }
                    if(count > 1){
                        return false;
                    }
                }
            }
        }
        vector<int> grid(2, 0);
        while(grid[1] <3){
            for(int i = 1; i < 4; ++i){
                for(int j = 1; j < 4; ++j){
                    if(board[i + 3 * grid[0] - 1][j + 3 * grid[1] - 1] == '.'){
                        continue;
                    }
                    int count = 0;
                    for(int m = 1; m < 4; ++m){
                        for(int n = 1; n < 4; ++n){
                            if(board[i + 3 * grid[0] - 1][j + 3 * grid[1] - 1] == board[m + 3 * grid[0] - 1][n + 3 * grid[1] - 1]){
                                count++;
                                
                            }
                            if(count > 1){
                                return false;
                            }
                        }
                    }

                }
            }
            if(grid[0] < 2){
                grid[0]++;
            }else{
                grid[0] = 0;
                grid[1]++;
            }
        }
       
        return true;
    }
};