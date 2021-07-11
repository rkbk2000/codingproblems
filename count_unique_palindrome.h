// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")
// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".
// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")

// Constraints:

// 3 <= s.length <= 10^5
// s consists of only lowercase English letters.

// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/submissions/

// Hints:
// What is the maximum number of length-3 palindromic strings?
// How can we keep track of the characters that appeared to the left of a given position?

// Runtime: 488 ms, faster than 54.55% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
// Memory Usage: 151.6 MB, less than 18.18% of C++ online submissions for Unique Length-3 Palindromic Subsequences.

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        // Count left and right occurrences for each distinct character in the string
        vector<int> left(26, 100001), right(26);

        for (auto i = 0; i < s.size(); i++)
        {
            left[s[i] - 'a'] = std::min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = i;
        }

        auto ans = 0;
        // Now check the number of occurrences between left and right
        for (auto i = 0; i < 26; i++)
        {
            if ((left[i] != 100001) && (left[i] != right[i]))
            {
                ans += std::unordered_set<char>(s.begin() + left[i] + 1, s.begin() + right[i]).size();
            }
        }
        return ans;
    }
};

// Using std::set instead of unordered set gives below results
// Runtime: 1400 ms, faster than 9.09% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
// Memory Usage: 13.4 MB, less than 63.64% of C++ online submissions for Unique Length-3 Palindromic Subsequences.

// Slightly better version
// Runtime: 328 ms, faster than 54.55% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
// Memory Usage: 151.7 MB, less than 18.18% of C++ online submissions for Unique Length-3 Palindromic Subsequences.

class Solution
{
public:
    int countPalindromicSubsequence(string s)
    {
        auto sz = s.size();

        // Count left and right occurrences for each distinct character in the string
        vector<int> left(26, sz), right(26);

        for (auto i = 0; i < sz; i++)
        {
            left[s[i] - 'a'] = std::min(left[s[i] - 'a'], i);
            right[s[i] - 'a'] = i;
        }

        auto ans = 0;
        // Now check the number of occurrences between left and right
        for (auto i = 0; i < 26; i++)
        {
            if ((left[i] != sz) && (left[i] != right[i]))
            {
                ans += std::unordered_set<char>(s.begin() + left[i] + 1, s.begin() + right[i]).size();
            }
        }
        return ans;
    }
};

// Another solution, same runtime
// Runtime: 348 ms, faster than 54.55% of C++ online submissions for Unique Length-3 Palindromic Subsequences.
// Memory Usage: 151.8 MB, less than 18.18% of C++ online submissions for Unique Length-3 Palindromic Subsequences.

class SolutionCmp
{
public:
    int countPalindromicSubsequence(string s)
    {
        auto sz = s.size();

        // Count left and right occurrences for each distinct character in the string
        vector<int> left(26, sz), right(26);

        for (auto i = 0; i < sz; i++)
        {
            auto cpos = s[i] - 'a';
            if (left[cpos] == sz)
            {
                left[cpos] = i;
            }
            // left[s[i] - 'a'] = std::min(left[s[i] - 'a'], i);
            right[cpos] = i;
        }

        auto ans = 0;
        // Now check the number of occurrences between left and right
        for (auto i = 0; i < 26; i++)
        {
            if ((left[i] != sz) && (left[i] != right[i]))
            {
                ans += std::unordered_set<char>(s.begin() + left[i] + 1, s.begin() + right[i]).size();
            }
        }
        return ans;
    }
};