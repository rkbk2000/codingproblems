// You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

// To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

// However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

// Return the maximum number of points you can achieve.

// abs(x) is defined as:

// x for x >= 0.
// -x for x < 0.

// Example 1:

// Input: points = [[1,2,3],[1,5,1],[3,1,1]]
// Output: 9
// Explanation:
// The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
// You add 3 + 5 + 3 = 11 to your score.
// However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
// Your final score is 11 - 2 = 9.
// Example 2:

// Input: points = [[1,5],[2,3],[4,2]]
// Output: 11
// Explanation:
// The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
// You add 5 + 3 + 4 = 12 to your score.
// However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
// Your final score is 12 - 1 = 11.

// Constraints:

// m == points.length
// n == points[r].length
// 1 <= m, n <= 10^5
// 1 <= m * n <= 10^5
// 0 <= points[r][c] <= 10^5
// https : //leetcode.com/contest/weekly-contest-250/problems/maximum-number-of-points-with-cost/

// Testcase:
// [[1,2,3],[1,5,1],[3,1,1]]
// [[1,5],[2,3],[4,2]]
// [[2,4,0,5,5],[0,5,4,2,5],[2,0,2,3,1],[3,0,5,5,2]]
// [[0,3,0,4,2],[5,4,2,4,1],[5,0,0,5,1],[2,0,1,0,3]]

// Output:
// 9
// 11
// 17
// 15

// 142 / 157 test cases passed.
// TLE for a large input size because of n^3
//  complexity O(m * n * n)
class SolutionTLE
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size(), n = points[0].size();

        // dp at each row - dp array
        vector<vector<long long>> dp(m + 1, vector<long long>(n, 0));
        for (auto j = 0; j < n; j++)
        {
            dp[0][j] = points[0][j];
        }

        // TODO: Find max from 0 to n-1 and vice versa
        for (int r = 1; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                long long mv = INT_MIN;
                for (int i = 0; i < n; i++)
                {
                    long long v = points[r][c] + dp[r - 1][i] - abs(c - i);
                    mv = std::max(mv, v);
                }
                dp[r][c] = mv;
            }
        }
        return *std::max_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

// Similar approach
// https://leetcode.com/problems/maximum-number-of-points-with-cost/discuss/1344893/Similar-to-931.-Minimum-Falling-Path-Sum

// Now instead of comparing all the values, we can assume that the max element is either to the left or to the right
// That would give us two independent for loops instead of a nested for loop.
// Runtime: 260 ms, faster than 100.00% of C++ online submissions for Maximum Number of Points with Cost.
// Memory Usage: 103.3 MB, less than 50.00% of C++ online submissions for Maximum Number of Points with Cost.
class Solution
{
public:
    long long maxPoints(vector<vector<int>> &points)
    {
        int m = points.size(), n = points[0].size();

        // dp at each row - dp array
        vector<vector<long long>> dp(m + 1, vector<long long>(n, 0));
        for (auto j = 0; j < n; j++)
        {
            dp[0][j] = points[0][j];
        }

        vector<long long> ldp(n, 0), rdp(n, 0);
        // TODO: Find max from 0 to n-1 and vice versa
        for (int r = 1; r < m; r++)
        {
            ldp[0] = dp[r - 1][0];
            for (int c = 1; c < n; ++c)
            {
                ldp[c] = std::max(ldp[c - 1], dp[r - 1][c] + c);
            }

            rdp.back() = dp[r - 1].back() - n + 1;
            for (int c = n - 2; c >= 0; --c)
            {
                rdp[c] = std::max(rdp[c + 1], dp[r - 1][c] - c);
            }

            for (int c = 0; c < n; ++c)
            {
                dp[r][c] = max(ldp[c] - c, rdp[c] + c) + points[r][c];
            }
        }
        return *std::max_element(dp[m - 1].begin(), dp[m - 1].end());
    }
};

class Solution
{
    long long maxPoints(vector<vector<int>> &points)
    {
        // Best soluation
        vector<long long> cur_row(p[0].size()), prev_row(p[0].size());
        for (auto &row : p)
        {
            for (long long j = 0, run_max = 0; j < row.size(); ++j)
            {
                run_max = max(run_max - 1, prev_row[j]);
                cur_row[j] = run_max;
            }
            for (long long j = row.size() - 1, run_max = 0; j >= 0; --j)
            {
                run_max = max(run_max - 1, prev_row[j]);
                cur_row[j] = max(cur_row[j], run_max) + row[j];
            }
            swap(cur_row, prev_row);
        }
        return *max_element(begin(prev_row), end(prev_row));
    }
}