// https://leetcode.com/problems/01-matrix/

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

// Example 1:

// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]
// Example 2:

// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 10^4
// 1 <= m * n <= 10^4
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.

// Testcase:
// [[0,0,0],[0,1,0],[0,0,0]]
// [[0,0,0],[0,1,0],[1,1,1]]

// Output:
// [[0,0,0],[0,1,0],[0,0,0]]
// [[0,0,0],[0,1,0],[1,2,1]]

// Runtime: 56 ms, faster than 95.88% of C++ online submissions for 01 Matrix.
// Memory Usage: 26.2 MB, less than 91.36% of C++ online submissions for 01 Matrix.

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rowSize = mat.size();
        if (rowSize == 0)
        {
            return mat;
        }
        int colSize = mat[0].size();

        vector<vector<int>> dist(rowSize, vector<int>(colSize, 10001));

        // Two pass solution.

        // First check left and top - Forward
        for (auto i = 0; i < rowSize; i++)
        {
            for (auto j = 0; j < colSize; j++)
            {

                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                }
                else
                {
                    // Check top
                    if (i > 0)
                    {
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    }
                    if (j > 0)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                    }
                }
            }
        }

        // Second pass - check right and bottom - Backward
        for (auto i = rowSize - 1; i >= 0; i--)
        {
            for (auto j = colSize - 1; j >= 0; j--)
            {
                if (i < rowSize - 1)
                {
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                }

                if (j < colSize - 1)
                {
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                }
            }
        }

        return dist;
    }
};