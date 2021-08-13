// https://leetcode.com/problems/set-matrix-zeroes/

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

// You must do it in place.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]
// Example 2:

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

// Constraints:

// m == matrix.length
// n == matrix[0].length
// 1 <= m, n <= 200
// -2^31 <= matrix[i][j] <= 2^31 - 1

// Follow up:

// A straightforward solution using O(mn) space is probably a bad idea.
// A simple improvement uses O(m + n) space, but still not the best solution.
// Could you devise a constant space solution?

// Hint:
// If any cell of the matrix has a zero we can record its row and column number using additional memory. But if you don't want to use extra memory then you can manipulate the array instead. i.e. simulating exactly what the question says.
// Setting cell values to zero on the fly while iterating might lead to discrepancies. What if you use some other integer value as your marker? There is still a better approach for this problem with 0(1) space.
// We could have used 2 sets to keep a record of rows/columns which need to be set to zero. But for an O(1) space solution, you can use one of the rows and and one of the columns to keep track of this information.
// We can use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero.

// Runtime: 12 ms, faster than 82.05% of C++ online submissions for Set Matrix Zeroes.
// Memory Usage: 13.3 MB, less than 19.76% of C++ online submissions for Set Matrix Zeroes.

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        auto setcol = false;
        for (auto i = 0; i < m; i++)
        {
            // Flag to indicate first column needs to be set
            if (matrix[i][0] == 0)
                setcol = true;
            for (auto j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    // Mark a cell in the first row and column
                    matrix[i][0] = 0; // Mark the first column cell
                    matrix[0][j] = 0; // Mark the first row cell
                }
            }
        }

        // Set the columns and rows starting from 1 to zero as needed
        for (auto i = 1; i < m; i++)
        {
            for (auto j = 1; j < n; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // check if first row needs to be set
        if (matrix[0][0] == 0)
        {
            for (auto j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Check if first column needs to be set
        if (setcol)
        {
            for (auto i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

// Approach: O(1) Space, Efficient Solution
// Intuition

// Rather than using additional variables to keep track of rows and columns to be reset, we use the matrix itself as the indicators.

// The idea is that we can use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero. This means for every cell instead of going to M+NM+N cells and setting it to zero we just set the flag in two cells.

// if cell[i][j] == 0 {
//     cell[i][0] = 0
//     cell[0][j] = 0
// }
// These flags are used later to update the matrix. If the first cell of a row is set to zero this means the row should be marked zero. If the first cell of a column is set to zero this means the column should be marked zero.

// Algorithm

// We iterate over the matrix and we mark the first cell of a row i and first cell of a column j, if the condition in the pseudo code above is satisfied. i.e. if cell[i][j] == 0.

// The first cell of row and column for the first row and first column is the same i.e. cell[0][0]. Hence, we use an additional variable to tell us if the first column had been marked or not and the cell[0][0] would be used to tell the same for the first row.

// Now, we iterate over the original matrix starting from second row and second column i.e. matrix[1][1] onwards. For every cell we check if the row r or column c had been marked earlier by checking the respective first row cell or first column cell. If any of them was marked, we set the value in the cell to 0. Note the first row and first column serve as the row_set and column_set that we used in the first approach.

// We then check if cell[0][0] == 0, if this is the case, we mark the first row as zero.

// And finally, we check if the first column was marked, we make all entries in it as zeros.

// In the above animation we iterate all the cells and mark the corresponding first row/column cell incase of a cell with zero value.

// We iterate the matrix we got from the above steps and mark respective cells zeroes.

// Complexity Analysis

// Time Complexity : O(M×N)
// Space Complexity : O(1)
