// You are given an m x n matrix maze (0-indexed) with empty cells (represented as '.') and walls (represented as '+'). You are also given the entrance of the maze, where entrance = [entrancerow, entrancecol] denotes the row and column of the cell you are initially standing at.

// In one step, you can move one cell up, down, left, or right. You cannot step into a cell with a wall, and you cannot step outside the maze. Your goal is to find the nearest exit from the entrance. An exit is defined as an empty cell that is at the border of the maze. The entrance does not count as an exit.

// Return the number of steps in the shortest path from the entrance to the nearest exit, or -1 if no such path exists.

// Example 1:

// Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]], entrance = [1,2]
// Output: 1
// Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
// Initially, you are at the entrance cell [1,2].
// - You can reach [1,0] by moving 2 steps left.
// - You can reach [0,2] by moving 1 step up.
// It is impossible to reach [2,3] from the entrance.
// Thus, the nearest exit is [0,2], which is 1 step away.
// Example 2:

// Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
// Output: 2
// Explanation: There is 1 exit in this maze at [1,2].
// [1,0] does not count as an exit since it is the entrance cell.
// Initially, you are at the entrance cell [1,0].
// - You can reach [1,2] by moving 2 steps right.
// Thus, the nearest exit is [1,2], which is 2 steps away.
// Example 3:

// Input: maze = [[".","+"]], entrance = [0,0]
// Output: -1
// Explanation: There are no exits in this maze.

// Constraints:

// maze.length == m
// maze[i].length == n
// 1 <= m, n <= 100
// maze[i][j] is either '.' or '+'.
// entrance.length == 2
// 0 <= entrancerow < m
// 0 <= entrancecol < n
// entrance will always be an empty cell.

// https : //leetcode.com/problems/nearest-exit-from-entrance-in-maze/submissions/

// Runtime: 152 ms, faster than 80.00% of C++ online submissions for Nearest Exit from Entrance in Maze.
// Memory Usage: 38.4 MB, less than 20.00% of C++ online submissions for Nearest Exit from Entrance in Maze.

#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        typedef std::pair<int, int> rowcol;

        // Queue for BFS
        queue<rowcol> myq;

        // visited cells
        set<rowcol> visited;
        visited.emplace(rowcol{entrance[0], entrance[1]});

        auto cnt = 0; // minimu steps

        auto m = maze.size(), n = maze[0].size();

        myq.push(rowcol{entrance[0], entrance[1]});
        while (!myq.empty())
        {
            auto sz = myq.size();
            for (auto i = 0; i < sz; i++)
            {
                auto v = myq.front();
                myq.pop();

                // Skip the entry cell
                if (!(v.first == entrance[0] && v.second == entrance[1]))
                {
                    // We are at the edge, return count
                    if (v.first == 0 || v.first == (m - 1) || v.second == 0 || v.second == (n - 1))
                    {
                        return cnt;
                    }
                }

                // r-1,c, r+1, c, r,c-1, r c+1

                auto top = rowcol{v.first - 1, v.second};
                if ((v.first > 0) && maze[v.first - 1][v.second] == '.' && visited.find(top) == visited.end())
                {
                    myq.push(top);
                    visited.emplace(top);
                }

                auto bottom = rowcol{v.first + 1, v.second};
                if ((v.first < m - 1) && maze[v.first + 1][v.second] == '.' && visited.find(bottom) == visited.end())
                {
                    myq.push(bottom);
                    visited.emplace(bottom);
                }

                auto left = rowcol{v.first, v.second - 1};
                if ((v.second > 0) && maze[v.first][v.second - 1] == '.' && visited.find(left) == visited.end())
                {
                    myq.push(left);
                    visited.emplace(left);
                }

                auto right = rowcol{v.first, v.second + 1};
                if ((v.second < n - 1) && maze[v.first][v.second + 1] == '.' && visited.find(right) == visited.end())
                {
                    myq.push(right);
                    visited.emplace(right);
                }
            }
            ++cnt;
        }

        return -1;
    }
};

// Better solution

// Runtime: 104 ms, faster than 80.00% of C++ online submissions for Nearest Exit from Entrance in Maze.
// Memory Usage: 30.6 MB, less than 20.00% of C++ online submissions for Nearest Exit from Entrance in Maze.

class Solution80
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        typedef std::pair<int, int> rowcol;

        // Queue for BFS
        queue<rowcol> myq;

        auto m = maze.size(), n = maze[0].size();
        // visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        visited[entrance[0]][entrance[1]] = true;

        auto cnt = 0; // minimu steps

        myq.push(rowcol{entrance[0], entrance[1]});
        while (!myq.empty())
        {
            auto sz = myq.size();
            for (auto i = 0; i < sz; i++)
            {
                auto v = myq.front();
                myq.pop();

                // Skip the entry cell
                if (!(v.first == entrance[0] && v.second == entrance[1]))
                {
                    // We are at the edge, return count
                    if (v.first == 0 || v.first == (m - 1) || v.second == 0 || v.second == (n - 1))
                    {
                        return cnt;
                    }
                }

                // r-1,c, r+1, c, r,c-1, r c+1

                if ((v.first > 0) && maze[v.first - 1][v.second] == '.' && !visited[v.first - 1][v.second])
                {
                    myq.push(rowcol{v.first - 1, v.second});
                    visited[v.first - 1][v.second] = true;
                }

                if ((v.first < m - 1) && maze[v.first + 1][v.second] == '.' && !visited[v.first + 1][v.second])
                {
                    myq.push(rowcol{v.first + 1, v.second});
                    visited[v.first + 1][v.second] = true;
                }

                if ((v.second > 0) && maze[v.first][v.second - 1] == '.' && !visited[v.first][v.second - 1])
                {
                    myq.push(rowcol{v.first, v.second - 1});
                    visited[v.first][v.second - 1] = true;
                }

                if ((v.second < n - 1) && maze[v.first][v.second + 1] == '.' && !visited[v.first][v.second + 1])
                {
                    myq.push(rowcol{v.first, v.second + 1});
                    visited[v.first][v.second + 1] = true;
                }
            }
            ++cnt;
        }

        return -1;
    }
};