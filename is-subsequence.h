// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters
// without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:

// Input: s = "abc", t = "ahbgdc"
// Output: true
// Example 2:

// Input: s = "axc", t = "ahbgdc"
// Output: false

// Constraints:

// 0 <= s.length <= 100
// 0 <= t.length <= 104
// s and t consist only of lowercase English letters.

// Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

// Test case:
// "abc"
// "ahbgdc"
// "axc"
// "ahbgdc"
// "abc"
// ""
// ""
// "abc"
// ""
// ""
// "b"
// "c"

// Output:
// true
// false
// false
// true
// true
// false

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.5 MB, less than 33.49% of C++ online submissions for Is Subsequence.
// https://leetcode.com/problems/is-subsequence/submissions/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {

        int pos = t.size();

        // Target string is empty
        if (pos == 0)
        {
            return s.size() == 0 ? true : false;
        }

        // Search string is empty
        if (s.size() == 0)
        {
            return true;
        }

        // Compare from last to first
        for (int i = s.size() - 1; i >= 0 && pos >= 0; i--)
        {
            pos = t.find_last_of(s[i], pos - 1);
            if (pos == string::npos)
            {
                return false;
            }
        }

        return true;
    }
};

// A better solution
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
// Memory Usage: 6.4 MB, less than 66.24% of C++ online submissions for Is Subsequence.
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        auto count = 0;
        for (auto i = 0; i < t.size() && count < s.size(); ++i)
        {
            if (s[count] == t[i])
                ++count;
        }

        return count == s.size();
    }
};