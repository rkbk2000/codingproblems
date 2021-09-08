// https://leetcode.com/problems/shifting-letters/
// 848. Shifting Letters
// You are given a string s of lowercase English letters and an integer array shifts of the same length.

// Call the shift() of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a').

// For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
// Now for each shifts[i] = x, we want to shift the first i + 1 letters of s, x times.

// Return the final string after all such shifts to s are applied.

// Example 1:

// Input: s = "abc", shifts = [3,5,9]
// Output: "rpl"
// Explanation: We start with "abc".
// After shifting the first 1 letters of s by 3, we have "dbc".
// After shifting the first 2 letters of s by 5, we have "igc".
// After shifting the first 3 letters of s by 9, we have "rpl", the answer.
// Example 2:

// Input: s = "aaa", shifts = [1,2,3]
// Output: "gfd"

// Constraints:

// 1 <= s.length <= 10^5
// s consists of lowercase English letters.
// shifts.length == s.length
// 0 <= shifts[i] <= 10^9

// Runtime: 200 ms, faster than 8.35% of C++ online submissions for Shifting Letters.
// Memory Usage: 67.8 MB, less than 45.50% of C++ online submissions for Shifting Letters.

class Solution
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        int sz = shifts.size();

        int64_t cur = shifts[sz - 1];

        for (auto i = sz - 1; i >= 0; i--)
        {
            if (i != sz - 1)
            {
                cur += shifts[i];
            }
            int64_t c = (cur + (s[i] - 'a' + 1)) % 26;
            if (!c)
            {
                s[i] = 'z';
            }
            else
            {
                s[i] = 'a' + (int)c - 1;
            }
        }
        return s;
    }
};

class Solution20ms
{
public:
    string shiftingLetters(string s, vector<int> &shifts)
    {
        for (int i = shifts.size() - 2; i >= 0; i--)
        {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }

        for (int i = 0; i < s.size(); i++)
        {
            s[i] = (s[i] - 'a' + shifts[i]) % 26 + 'a';
        }

        return s;
    }
};