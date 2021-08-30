// https://leetcode.com/problems/range-addition-ii/

// 598. Range Addition II
// You are given an m x n matrix M initialized with all 0's and an array of operations ops, where ops[i] = [ai, bi] means M[x][y] should be incremented by one for all 0 <= x < ai and 0 <= y < bi.

// Count and return the number of maximum integers in the matrix after performing all the operations.

// Example 1:

// Input: m = 3, n = 3, ops = [[2,2],[3,3]]
// Output: 4
// Explanation: The maximum integer in M is 2, and there are four of it in M. So return 4.
// Example 2:

// Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
// Output: 4
// Example 3:

// Input: m = 3, n = 3, ops = []
// Output: 9

// Constraints:

// 1 <= m, n <= 4 * 10^4
// 1 <= ops.length <= 10^4
// ops[i].length == 2
// 1 <= ai <= m
// 1 <= bi <= n

// Runtime: 18 ms, faster than 5.89% of C++ online submissions for Range Addition II.
// Memory Usage: 10.9 MB, less than 85.11% of C++ online submissions for Range Addition II.

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        // Find min x, min y
        auto minx = m, miny = n;
        for (auto &op : ops)
        {
            minx = std::min(minx, op[0]);
            miny = std::min(miny, op[1]);
        }
        return minx * miny;
    }
};