// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

// Example 1:

// Input: grid = [[1,0],[0,1]]
// Output: 3
// Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
// Example 2:

// Input: grid = [[1,1],[1,0]]
// Output: 4
// Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
// Example 3:

// Input: grid = [[1,1],[1,1]]
// Output: 4
// Explanation: Can't change any 0 to 1, only one island with area = 4.

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 500
// grid[i][j] is either 0 or 1.

// Brute force solution TLE, 67 / 75 test cases passed.
class SolutionTLE
{
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, -1, 0, 1};

public:
    int largestIsland(vector<vector<int>> &grid)
    {
        // Brute force - Chane every 0 to a 1 and check with DFS

        int sz = grid.size();
        int ans = 0;
        auto haszero = false;

        for (auto r = 0; r < sz; r++)
        {
            for (auto c = 0; c < sz; c++)
            {
                if (grid[r][c] == 0)
                {
                    haszero = true;
                    grid[r][c] = 1;
                    ans = std::max(ans, getArea(grid, r, c));
                    grid[r][c] = 0;
                }
            }
        }
        return haszero ? ans : sz * sz;
    }

    int getArea(vector<vector<int>> &grid, int r0, int c0)
    {
        int sz = grid.size();
        std::stack<int> stk;
        unordered_set<int> seen;
        stk.push(r0 * sz + c0);
        seen.emplace(r0 * sz + c0);

        while (!stk.empty())
        {
            int val = stk.top();
            stk.pop();
            int r = val / sz, c = val % sz;
            for (int k = 0; k < 4; ++k)
            {
                int nr = r + dr[k], nc = c + dc[k];
                if (!seen.count(nr * sz + nc) && 0 <= nr && nr < sz &&
                    0 <= nc && nc < sz && grid[nr][nc] == 1)
                {
                    stk.push(nr * sz + nc);
                    seen.emplace(nr * sz + nc);
                }
            }
        }

        return seen.size();
    }
};
