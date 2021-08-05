// Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

// Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.

// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation:
// Alex starts first, and can only take the first 5 or the last 5.
// Say he takes the first 5, so that the row becomes [3, 4, 5].
// If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10 points.
// If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alex, so we return true.

// Constraints:

// 2 <= piles.length <= 500
// piles.length is even.
// 1 <= piles[i] <= 500
// sum(piles) is odd.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Stone Game.
// Memory Usage: 7.4 MB, less than 97.13% of C++ online submissions for Stone Game.

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int asum{0}, // Alex's sum
            lsum{0}, // Lee's sum
            l = 0, r = piles.size() - 1;

        // Take the stones optimally
        while (l < r)
        {
            // Take the maximum
            if (piles[l] > piles[r])
            {
                asum += piles[l++];
            }
            else
            {
                asum += piles[r--];
            }

            // Take the minimum
            if (piles[l] < piles[r])
            {
                lsum += piles[l++];
            }
            else
            {
                lsum += piles[r--];
            }
        }
        return asum > lsum;
    }
};

// Output should always be true according to mathematical calculation.
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};

// Dynamic programming
// Approach 1: Dynamic Programming
// Intuition

// Let's change the game so that whenever Lee scores points, it deducts from Alex's score instead.

// Let dp(i, j) be the largest score Alex can achieve where the piles remaining are piles[i], piles[i+1], ..., piles[j]. This is natural in games with scoring: we want to know what the value of each position of the game is.

// We can formulate a recursion for dp(i, j) in terms of dp(i+1, j) and dp(i, j-1), and we can use dynamic programming to not repeat work in this recursion. (This approach can output the correct answer, because the states form a DAG (directed acyclic graph).)

// Algorithm

// When the piles remaining are piles[i], piles[i+1], ..., piles[j], the player who's turn it is has at most 2 moves.

// The person who's turn it is can be found by comparing j-i to N modulo 2.

// If the player is Alex, then she either takes piles[i] or piles[j], increasing her score by that amount. Afterwards, the total score is either piles[i] + dp(i+1, j), or piles[j] + dp(i, j-1); and we want the maximum possible score.

// If the player is Lee, then he either takes piles[i] or piles[j], decreasing Alex's score by that amount. Afterwards, the total score is either -piles[i] + dp(i+1, j), or -piles[j] + dp(i, j-1); and we want the minimum possible score.

// Complexity Analysis

// Time Complexity: O(N^2), where NN is the number of piles.

// Space Complexity: O(N^2) the space used storing the intermediate results of each subgame.
class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int N = piles.size();

        // dp[i+1][j+1] = the value of the game [piles[i], ..., piles[j]]
        int dp[N + 2][N + 2];
        memset(dp, 0, sizeof(dp));

        for (int size = 1; size <= N; ++size)
            for (int i = 0, j = size - 1; j < N; ++i, ++j)
            {
                int parity = (j + i + N) % 2; // j - i - N; but +x = -x (mod 2)
                if (parity == 1)
                    dp[i + 1][j + 1] = max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                else
                    dp[i + 1][j + 1] = min(-piles[i] + dp[i + 2][j + 1], -piles[j] + dp[i + 1][j]);
            }

        return dp[1][N] > 0;
    }
};

// Approach 2: Mathematical
// Intuition and Algorithm

// Alex clearly always wins the 2 pile game. With some effort, we can see that she always wins the 4 pile game.

// If Alex takes the first pile initially, she can always take the third pile. If she takes the fourth pile initially, she can always take the second pile. At least one of first + third, second + fourth is larger, so she can always win.

// We can extend this idea to N piles. Say the first, third, fifth, seventh, etc. piles are white, and the second, fourth, sixth, eighth, etc. piles are black. Alex can always take either all white piles or all black piles, and one of the colors must have a sum number of stones larger than the other color.

// Hence, Alex always wins the game.

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};
// Complexity Analysis

// Time and Space Complexity: O(1)O(1).