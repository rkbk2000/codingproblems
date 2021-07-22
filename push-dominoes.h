// There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

// After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

// For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

// You are given a string dominoes representing the initial state where:

// dominoes[i] = 'L', if the ith domino has been pushed to the left,
// dominoes[i] = 'R', if the ith domino has been pushed to the right, and
// dominoes[i] = '.', if the ith domino has not been pushed.
// Return a string representing the final state.

// Example 1:

// Input: dominoes = "RR.L"
// Output: "RR.L"
// Explanation: The first domino expends no additional force on the second domino.
// Example 2:

// Input: dominoes = ".L.R...LR..L.."
// Output: "LL.RR.LLRRLL.."

// Constraints:

// n == dominoes.length
// 1 <= n <= 105
// dominoes[i] is either 'L', 'R', or '.'.

// https://leetcode.com/problems/push-dominoes/

// Testcase:
// "RR.L"
// ".L.R...LR..L.."
// "LLLLL.LR."
// "......L"
// "R......."
// ".R........L"
// ".R.......L"

// Output:
// "RR.L"
// "LL.RR.LLRRLL.."
// "LLLLLLLRR"
// "LLLLLLL"
// "RRRRRRRR"
// ".RRRRRLLLLL"
// ".RRRR.LLLL"

// Runtime: 36 ms, faster than 24.60% of C++ online submissions for Push Dominoes.
// Memory Usage: 12.6 MB, less than 35.18% of C++ online submissions for Push Dominoes.

class Solution
{
public:
    string pushDominoes(string dominoes)
    {
        int lastLR = -1; // Position of last L or R, remains as is when we find a .
        int sz = dominoes.size();
        for (auto i = 0; i < sz; i++)
        {
            switch (dominoes[i])
            {
            case 'L':
                // Check if the lastLR before .s is a R or L or not set
                if (lastLR == -1 || dominoes[lastLR] == 'L')
                {
                    for (auto j = lastLR + 1; j < i; j++)
                    {
                        // Fill all Ls
                        dominoes[j] = 'L';
                    }
                }
                else if (dominoes[lastLR] == 'R')
                {
                    // Equally set Ls and Rs
                    int toFill = (i - lastLR - 1) / 2;
                    for (auto j = 1; j <= toFill; j++)
                    {
                        dominoes[lastLR + j] = 'R';
                        dominoes[i - j] = 'L';
                    }
                }
                lastLR = i;
                break;
            case 'R':
                // Go further
                lastLR = i;
                break;
            }
        }

        // Traverse from last to first
        lastLR = sz;
        for (auto i = sz - 1; i >= 0; i--)
        {
            switch (dominoes[i])
            {
            case 'R':
                // Check if the lastLR before .s is a R or L or not set
                if (lastLR == sz || dominoes[lastLR] == 'R')
                {
                    for (auto j = lastLR - 1; j > i; j--)
                    {
                        // Fill all Ls
                        dominoes[j] = 'R';
                    }
                }
                else if (dominoes[lastLR] == 'L')
                {
                    // Equally set Ls and Rs
                    int toFill = (lastLR - i - 1) / 2;
                    for (auto j = 1; j <= toFill; j++)
                    {
                        dominoes[lastLR - j] = 'L';
                        dominoes[i + j] = 'R';
                    }
                }
                lastLR = i;
                break;
            case 'L':
                // Go further
                lastLR = i;
                break;
            }
        }
        return dominoes;
    }
};

// Another solution
// Runtime: 32 ms, faster than 29.52% of C++ online submissions for Push Dominoes.
// Memory Usage: 12.5 MB, less than 35.79% of C++ online submissions for Push Dominoes.
class Solution1
{
public:
    string pushDominoes(string dominoes)
    {
        int lastLR = 0, firstLR = -1; // Position of last L or R, remains as is when we find a .
        int sz = dominoes.size();
        for (auto i = 1; i < sz; i++)
        {
            if (dominoes[i] == '.')
            {
                continue;
            }

            if (dominoes[i] == dominoes[lastLR])
            {
                // LL or RR combination
                for (auto j = lastLR; j <= i; j++)
                {
                    // Fill all Ls or Rs
                    dominoes[j] = dominoes[i];
                }
            }
            else if (dominoes[i] < dominoes[lastLR])
            {
                // R L combination, half Ls and half Rs
                int toFill = (i - lastLR - 1) / 2;
                for (auto j = 1; j <= toFill; j++)
                {
                    dominoes[lastLR + j] = 'R';
                    dominoes[i - j] = 'L';
                }
            }
            lastLR = i;
            if (firstLR == -1)
            {
                firstLR = lastLR;
            }
        }

        // Handle ...L*
        if (firstLR != -1 && dominoes[0] == '.' && dominoes[firstLR] == 'L')
        {
            std::fill(dominoes.begin(), dominoes.begin() + firstLR, 'L');
        }

        // Handle *R...
        if (lastLR < sz && dominoes[lastLR] == 'R' && dominoes[sz - 1] == '.')
        {
            for (auto i = lastLR + 1; i < sz; i++)
            {
                dominoes[i] = 'R';
            }
        }

        return dominoes;
    }
};

// Using a set
// Runtime: 208 ms, faster than 5.04% of C++ online submissions for Push Dominoes.
// Memory Usage: 49.2 MB, less than 5.04% of C++ online submissions for Push Dominoes.
class SolutionSet
{
public:
    string pushDominoes(string dominoes)
    {
        // Set of indexes having either L or R
        std::set<int> lr;

        int sz = dominoes.size();
        for (auto i = 0; i < sz; i++)
        {
            if (dominoes[i] == '.')
            {
                continue;
            }
            lr.emplace(i);
        }

        int prev = -1;
        auto it = lr.begin();
        for (; it != lr.end(); it++)
        {
            if (prev == -1)
            {
                if (dominoes[*it] == 'L')
                {
                    std::fill(dominoes.begin(), dominoes.begin() + (*it), 'L');
                }
            }
            else
            {
                if (dominoes[*it] == dominoes[prev])
                {
                    // LL or RR combination
                    for (auto j = prev; j <= *it; j++)
                    {
                        // Fill all Ls or Rs
                        dominoes[j] = dominoes[*it];
                    }
                }
                else if (dominoes[*it] < dominoes[prev])
                {
                    int toFill = (*it - prev - 1) / 2;
                    for (auto j = 1; j <= toFill; j++)
                    {
                        dominoes[prev + j] = 'R';
                        dominoes[*it - j] = 'L';
                    }
                }
            }
            prev = *it;
        }

        if (prev != -1 && dominoes[prev] == 'R' && dominoes[sz - 1] == '.')
        {
            // Handle *R...
            for (auto i = prev; i < sz; i++)
            {
                dominoes[i] = 'R';
            }
        }

        return dominoes;
    }
};