// https://leetcode.com/problems/decode-ways/

// A message containing letters from A-Z can be encoded into numbers using the following mapping:

// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// To decode an encoded message, all the digits must be grouped then mapped back into letters using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:

// "AAJF" with the grouping (1 1 10 6)
// "KJF" with the grouping (11 10 6)
// Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".

// Given a string s containing only digits, return the number of ways to decode it.

// The answer is guaranteed to fit in a 32-bit integer.

// Example 1:

// Input: s = "12"
// Output: 2
// Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).
// Example 2:

// Input: s = "226"
// Output: 3
// Explanation: "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
// Example 3:

// Input: s = "0"
// Output: 0
// Explanation: There is no character that is mapped to a number starting with 0.
// The only valid mappings with 0 are 'J' -> "10" and 'T' -> "20", neither of which start with 0.
// Hence, there are no valid ways to decode this since all digits need to be mapped.
// Example 4:

// Input: s = "06"
// Output: 0
// Explanation: "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06").

// Constraints:

// 1 <= s.length <= 100
// s contains only digits and may contain leading zero(s).

// Runtime: 4 ms, faster than 31.73% of C++ online submissions for Decode Ways.
// Memory Usage: 6.3 MB, less than 24.64% of C++ online submissions for Decode Ways.

class Solution
{
public:
    int numDecodings(string s)
    {
        int sz = s.size();
        vector<int> dp(sz + 1, 0);
        dp[0] = 1; // First digit, always 1 possibility
        dp[1] = (s[0] != '0') ? 1 : 0;
        for (auto i = 2; i <= sz; i++)
        {
            // Previous digit
            auto n1 = s[i - 1] - '0';
            // Previous 2 digit number to calculate the combination
            auto n2 = n1 + (s[i - 2] - '0') * 10;

            if (n1 > 0)
            {
                dp[i] += dp[i - 1];
            }

            // Check for valid 2 digit values
            if (n2 >= 10 && n2 <= 26)
            {
                dp[i] += dp[i - 2];
            }
        }
        return dp[sz];
    }
};

// Better one
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage: 6.2 MB, less than 38.55% of C++ online submissions for Decode Ways.
class Solution100
{
public:
    int numDecodings(string s)
    {
        int sz = s.size();
        vector<int> dp(sz + 1, 0);
        dp[0] = 1; // First digit, always 1 possibility
        dp[1] = (s[0] != '0') ? 1 : 0;
        for (auto i = 2; i <= sz; i++)
        {
            // Previous digit
            auto n1 = s[i - 1] - '0';
            // Previous 2 digit number to calculate the combination
            auto n2 = s[i - 2] - '0';

            if (n1 > 0)
            {
                dp[i] += dp[i - 1];
            }

            if (n2 > 0)
            {
                // Check for valid 2 digit values
                if ((n2 == 1) || ((n2 == 2) && n1 <= 6))
                {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[sz];
    }
};

// Better runtime and memory
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
// Memory Usage: 6 MB, less than 87.78% of C++ online submissions for Decode Ways.
class SolutionOM
{
public:
    int numDecodings(string s)
    {
        int sz = s.size();
        auto dp0 = 1; // start with 1
        auto dp1 = (s[0] != '0') ? 1 : 0;
        auto dp = 0;

        for (auto i = 2; i <= sz; i++)
        {
            // Previous 2 digit number to calculate the combination
            if (s[i - 1] > '0')
            {
                dp += dp1;
            }

            // Check for valid 2 digit values
            if ((s[i - 2] == '1') || ((s[i - 2] == '2') && s[i - 1] <= '6'))
            {
                dp += dp0;
            }

            dp0 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};