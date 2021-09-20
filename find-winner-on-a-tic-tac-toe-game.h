// https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

// 1275. Find Winner on a Tic Tac Toe Game
// Tic-tac-toe is played by two players A and B on a 3 x 3 grid.

// Here are the rules of Tic-Tac-Toe:

// Players take turns placing characters into empty squares (" ").
// The first player A always places "X" characters, while the second player B always places "O" characters.
// "X" and "O" characters are always placed into empty squares, never on filled ones.
// The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
// The game also ends if all squares are non-empty.
// No more moves can be played if the game is over.
// Given an array moves where each element is another array of size 2 corresponding to the row and column of the grid where they mark their respective character in the order in which A and B play.

// Return the winner of the game if it exists (A or B), in case the game ends in a draw return "Draw", if there are still movements to play return "Pending".

// You can assume that moves is valid (It follows the rules of Tic-Tac-Toe), the grid is initially empty and A will play first.

// Example 1:

// Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
// Output: "A"
// Explanation: "A" wins, he always plays first.
// "X  "    "X  "    "X  "    "X  "    "X  "
// "   " -> "   " -> " X " -> " X " -> " X "
// "   "    "O  "    "O  "    "OO "    "OOX"
// Example 2:

// Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
// Output: "B"
// Explanation: "B" wins.
// "X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
// "   " -> " O " -> " O " -> " O " -> "XO " -> "XO "
// "   "    "   "    "   "    "   "    "   "    "O  "
// Example 3:

// Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
// Output: "Draw"
// Explanation: The game ends in a draw since there are no moves to make.
// "XXO"
// "OOX"
// "XOX"
// Example 4:

// Input: moves = [[0,0],[1,1]]
// Output: "Pending"
// Explanation: The game has not finished yet.
// "X  "
// " O "
// "   "

// Constraints:

// 1 <= moves.length <= 9
// moves[i].length == 2
// 0 <= moves[i][j] <= 2
// There are no repeated elements on moves.
// moves follow the rules of tic tac toe.

// Hints:
// It's straightforward to check if A or B won or not, check for each row/column/diag if all the three are the same.
// Then if no one wins, the game is a draw iff the board is full, i.e. moves.length = 9 otherwise is pending.

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
// Memory Usage: 8.2 MB, less than 96.15% of C++ online submissions for Find Winner on a Tic Tac Toe Game.

class Solution
{
public:
    string tictactoe(vector<vector<int>> &moves)
    {
        vector<char> board(9, 'a');
        // Convert into 1-D array
        bool aMove = true;
        for (auto &move : moves)
        {
            int pos = move[0] * 3 + move[1];
            board[pos] = aMove ? 'X' : 'O';
            aMove = !aMove;
        }

        // Check rows
        for (int start = 0; start < 9; start += 3)
        {
            if (board[start] == 'a')
                continue;
            if (board[start] == board[start + 1] && board[start + 1] == board[start + 2])
                return board[start] == 'X' ? "A" : "B";
        }

        // Check columns
        for (int start = 0; start < 3; start++)
        {
            if (board[start] == 'a')
                continue;
            if (board[start] == board[start + 3] && board[start + 3] == board[start + 6])
                return board[start] == 'X' ? "A" : "B";
        }

        // check diagonals
        if (board[0] != 'a' && board[0] == board[4] && board[4] == board[8])
            return board[0] == 'X' ? "A" : "B";
        if (board[2] != 'a' && board[2] == board[4] && board[4] == board[6])
            return board[2] == 'X' ? "A" : "B";

        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};