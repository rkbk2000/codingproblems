// 37. Sudoku Solver
// https://leetcode.com/problems/sudoku-solver/submissions/
// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:

// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.

// Runtime: 20 ms, faster than 77.62% of C++ online submissions for Sudoku Solver.
// Memory Usage: 6.3 MB, less than 83.32% of C++ online submissions for Sudoku Solver.

class Solution
{
    static const char EMPTY = '.';

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        canSolveFrom(0, 0, board);
    }

    bool canSolveFrom(int row, int col, vector<vector<char>> &board)
    {
        // Base case, end of columns
        if (col == board[row].size())
        {
            col = 0;
            row++;
            if (row == board.size())
            {
                // We have reached the end
                return true;
            }
        }

        // Skip the already filled cells, empty cells contain a .
        if (board[row][col] != EMPTY)
        {
            return canSolveFrom(row, col + 1, board);
        }

        // Now place the digits
        for (int d = 1; d <= 9; d++)
        {
            char c = d + '0';
            // Can I place d in the current cell?
            if (canPlace(row, col, board, c))
            {
                board[row][col] = c;
                if (canSolveFrom(row, col + 1, board))
                {
                    return true;
                }
            }
            // Un select
            board[row][col] = EMPTY;
        }

        // We cannot solve, return false
        return false;
    }

    bool canPlace(int row, int col, const vector<vector<char>> &board, char ch)
    {
        // Check the current column
        for (int r = 0; r < 9; r++)
        {
            if (board[r][col] == ch)
            {
                return false;
            }
        }

        // Check the current row
        for (int c = 0; c < 9; c++)
        {
            if (board[row][c] == ch)
            {
                return false;
            }
        }

        // Check 3x3 grid
        int rowStart = (row / 3) * 3, rowEnd = rowStart + 3;
        int colStart = (col / 3) * 3, colEnd = colStart + 3;

        for (int r = rowStart; r < rowEnd; r++)
        {
            for (int c = colStart; c < colEnd; c++)
            {
                if (board[r][c] == ch)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
