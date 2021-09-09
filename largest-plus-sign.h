// https://leetcode.com/problems/largest-plus-sign/

// 764. Largest Plus Sign
// You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.

// Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

// An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

// Example 1:

// Input: n = 5, mines = [[4,2]]
// Output: 2
// Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
// Example 2:

// Input: n = 1, mines = [[0,0]]
// Output: 0
// Explanation: There is no plus sign, so return 0.

// Constraints:

// 1 <= n <= 500
// 1 <= mines.length <= 5000
// 0 <= xi, yi < n
// All the pairs (xi, yi) are unique.

// Hint:
// For each direction such as "left", find left[r][c] = the number of 1s you will see before a zero starting at r, c and walking left. You can find this in N^2 time with a dp. The largest plus sign at r, c is just the minimum of left[r][c], up[r][c] etc.

// TLE O(n^3)
class SolutionTLE
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<bool>> zeros(n, vector<bool>(n, true));

        for (auto &row : mines)
        {
            //Set the mines
            zeros[row[0]][row[1]] = false;
        }

        int result = 0;
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                int k = 0;

                if (!zeros[r][c])
                    continue;
                // check boundary, left, right, up and down
                while (k <= r && r < n - k && k <= c && c < n - k && zeros[r - k][c] && zeros[r + k][c] && zeros[r][c - k] && zeros[r][c + k])
                    k++;

                if (k > result)
                    result = k;
            }
        }

        return result;
    }
};

// Using DP

// Intution
// How can we improve our bruteforce? One way is to try to speed up the inner loop involving k, the order of the candidate plus sign. If we knew the longest possible arm length
//  L_u, L_l, L_d, L_r  in each direction from a center, we could know the order min(L_u, L_l, L_d, L_r) of a plus sign at that center. We could find these lengths separately
// using dynamic programming.

// Algorithm

// For each (cardinal) direction, and for each coordinate (r, c) let's compute the count of that coordinate: the longest line of '1's starting from (r, c) and going in that direction.
// With dynamic programming, it is either 0 if grid[r][c] is zero, else it is 1 plus the count of the coordinate in the same direction. For example, if the direction is left and
// we have a row like 01110110, the corresponding count values are 01230120, and the integers are either 1 more than their successor, or 0. For each square, we want dp[r][c] to
// end up being the minimum of the 4 possible counts. At the end, we take the maximum value in dp.

// Check al the directions using a DP
class Solution
{
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<bool>> zeros(n, vector<bool>(n, true));

        for (auto &row : mines)
        {
            //Set the mines
            zeros[row[0]][row[1]] = false;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        int result = 0, count;
        for (int r = 0; r < n; r++)
        {
            count = 0;
            for (int c = 0; c < n; c++)
            {
                count = !zeros[r][c] ? 0 : count + 1;
                dp[r][c] = count;
            }
            count = 0;
            for (int c = n - 1; c >= 0; c--)
            {
                count = !zeros[r][c] ? 0 : count + 1;
                dp[r][c] = std::min(dp[r][c], count);
            }
        }

        for (int c = 0; c < n; c++)
        {
            count = 0;
            for (int r = 0; r < n; r++)
            {
                count = !zeros[r][c] ? 0 : count + 1;
                dp[r][c] = std::min(dp[r][c], count);
            }
            count = 0;
            for (int r = n - 1; r >= 0; r--)
            {
                count = !zeros[r][c] ? 0 : count + 1;
                dp[r][c] = std::min(dp[r][c], count);
                result = std::max(dp[r][c], result);
            }
        }
        return result;
    }
};