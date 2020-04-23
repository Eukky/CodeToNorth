// 37. Sudoku Solver
// Write a program to solve a Sudoku puzzle by filling the empty cells.
// A sudoku solution must satisfy all of the following rules:
// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// Empty cells are indicated by the character '.'.

// Note:
// The given board contain only digits 1-9 and the character '.'.
// You may assume that the given Sudoku puzzle will have a single unique solution.
// The given board size is always 9x9.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fill(board, 0, 0);
    }
    
    bool fill(vector<vector<char>>& board, int i, int j){
        if(j == 9){
            return true;
        }
        if(i >= 9){
            return fill(board, 0, j + 1);
        }
        if(board[i][j] == '.'){
            for(int k = 1; k <= 9; ++k){
                board[i][j] = k + '0';
                if(isValid(board, i, j)){
                    if(fill(board, i + 1, j)){
                        return true;
                    }
                }
                board[i][j] = '.';
            }
        }else{
            return fill(board, i + 1, j);
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int i, int j){
        for(int m = 0; m < 9; ++m){
            if(board[i][j] == board[m][j] && m != i){
                return false;
            }
        }
        for(int n = 0; n < 9; ++n){
            if(board[i][j] == board[i][n] && n != j){
                return false;
            }
        }
        for(int m = i / 3 * 3; m < i / 3 * 3 + 3; ++m){
            for(int n = j / 3 * 3; n < j / 3 * 3 + 3; ++n){
                if((m != i || n != j) && board[i][j] == board[m][n]){
                    return false;
                }
            }
        }
        return true;
    }
};